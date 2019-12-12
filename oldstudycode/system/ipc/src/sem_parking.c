#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/sem.h>
#include <unistd.h>
union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};
int P(int semid,unsigned short semnum)
{
	struct sembuf bufs[1] = {{semnum,-1,0}};
    return semop(semid,bufs,1);
}
int V(int semid,unsigned short semnum)
{
	struct sembuf bufs[1] = {{semnum,1,0}};
    return semop(semid,bufs,1);

}
int main(void )
{
	int semid = semget(IPC_PRIVATE,1,IPC_CREAT|0666);
	if(semid < 0)
	{
		fprintf(stderr,"semget: %s\n",strerror(errno));
		exit(1);
	}
	union semun un;
	un.val = 3;
	if(semctl(semid,0,SETVAL,un)<0)
	{
		fprintf(stderr,"semctl: %s\n",strerror(errno));
		exit(1);
	}
	pid_t pid;
	int i;
	for(i=0;i<5;i++)
	{
	if((pid=fork())<0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}
	else if(pid ==0)
	{
		P(semid,0);
		printf("%d park in!\n",getpid());
		sleep(5);
		printf("%d park out!\n",getpid());
		V(semid,0);
		exit(0);
	}else
	{
		
	}
	}
	for(;i >0;i--)
	  wait(NULL);
	wait(NULL);

	semctl(semid,0,IPC_RMID,NULL);
	return 0;
}
