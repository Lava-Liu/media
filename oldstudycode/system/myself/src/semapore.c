#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/sem.h>
#include <pthread.h>
#include <assert.h>
union semun
{
	int val;
	struct semid_ds *ds;
	unsigned short *array;
};
int I(int semnum,int val)
{
  int semid = semget(IPC_PRIVATE,semnum,IPC_CREAT|IPC_CREAT|IPC_EXCL|0666);
  if(semid < 0)
  {
	  fprintf(stderr,"%s\n",strerror(errno));
	  exit(1);
  }
  union semun u;
  unsigned short *array = (unsigned short *)calloc(semnum,sizeof(unsigned short));
  int i = 0;
  for(;i < semnum;i++)
  {
	  array[i] = val;
  }
  u.array = array;
  if(semctl(semid,0,SETALL,u)<0)
  {
	  fprintf(stderr,"semctl1: %s \n",strerror(errno));
	  exit(1);
  }
  free(array);
  return semid;
}
void P(int semid,int semnum,int val)
{
	assert(val >= 0);
	struct sembuf ops[1] = {{semnum,-val,SEM_UNDO}};
	if(semop(semid,ops,1)<0)
	{
		fprintf(stderr,"P(semop): %s\n",strerror(errno));
		exit(1);
	}
}
void V(int semid,int semnum,int val)
{
	assert(val >= 0);
	struct sembuf ops[1]= {{semnum,val,SEM_UNDO}};
	if(semop(semid,ops,1)<0)
	{
		fprintf(stderr,"P(semop): %s\n",strerror(errno));
		exit(1);
		
	}
}
void D(int semid)
{
	if(semctl(semid,0,IPC_RMID,NULL)<0)
	{
		fprintf(stderr,"semctl: %s\n",strerror(errno));
		exit(1);
	}
}
void *th_1(void *arg)
{
	int semid=(int)arg;
	P(semid,0,1);
	printf("I am:%o I park the car\n",pthread_self());
	sleep(5);
	printf("I am:%o I leave the parking space\n",pthread_self());

	V(semid,0,1);
}
int main(void)
{
	int semid=I(1,3);
	pthread_t th1,th2,th3,th4,th5;
	if(pthread_create(&th1,NULL,th_1,(void *)semid)<0)
	{
		fprintf(stderr,"semctl: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&th2,NULL,th_1,(void *)semid)<0)
	{
		fprintf(stderr,"semctl: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&th3,NULL,th_1,(void *)semid)<0)
	{
		fprintf(stderr,"semctl: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&th4,NULL,th_1,(void *)semid)<0)
	{
		fprintf(stderr,"semctl: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&th5,NULL,th_1,(void *)semid)<0)
	{
		fprintf(stderr,"semctl: %s\n",strerror(errno));
		exit(1);
	}
	pause();

	return 0;
}
