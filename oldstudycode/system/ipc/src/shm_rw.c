#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/shm.h>
#include <unistd.h>
#define SHM_SIZE 4096
int main(void)
{
	key_t key = ftok(getcwd(NULL,0),1);
	if(key < 0)
	{
		fprintf(stderr,"ftok: %s\n",strerror(errno));
		exit(1);
	}
	printf("key: %x\n",key);

	int shmid = shmget(key,SHM_SIZE,IPC_CREAT|IPC_EXCL|0666);
	if(shmid < 0)
	{
		fprintf(stderr,"shmget: %s\n",strerror(errno));
		exit(1);
	}
	printf("shmid: %d\n",shmid);
	pid_t pid;
	pid = fork();
	if(pid < 0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}
	else if(pid == 0)
	{
		sleep(5);
	    int *ptr=(int *)shmat(shmid,NULL,0);
		if(ptr == (int *)-1)
		{
			fprintf(stderr,"shmat: %s\n",strerror(errno));
			exit(1);
		}
		printf("ptr int child: %p -- > %d\n",ptr,*ptr);
		shmdt(ptr);
		exit(0);
	}
	else
	{
		int *ptr=(int *)shmat(shmid,NULL,0);
		if(ptr == (int *)-1)
		{
			fprintf(stderr,"shmat: %s\n",strerror(errno));
			exit(1);
		}
		*ptr = 100;
		printf("ptr in parent: %p -- > %d\n",ptr,*ptr);
		shmdt(ptr);
		wait(NULL);
	}
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
