#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "pv.h"
#include <sys/sem.h>
#include <assert.h>
#include <malloc.h>
union semun
{
	int val;
	struct semid_ds *ds;
	unsigned short *array;
};
int  I(int semnum,int val)
{
	int semid = semget(IPC_PRIVATE,semnum,IPC_CREAT|IPC_EXCL|0777);
	if(semid < 0)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		return -1;
	}
	union semun u;
	unsigned short *array = (unsigned short *)calloc(semnum,
			sizeof(unsigned short));
	int i = 0;
	for(;i < semnum; i++)
	{
		array[i] = val;
	}
	u.array = array;
	if(semctl(semid,0,SETALL,u)<0)
	{
		fprintf(stderr,"semctl1:%s \n",strerror(errno));
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
		fprintf(stderr,"P(semop); %s\n",strerror(errno));
		exit(1);
	}
}
void V(int semid,int semnum,int val)
{
	assert(val >= 0);
	struct sembuf ops[1] = {{semnum,val,SEM_UNDO}};
	if(semop(semid,ops,1)<0)
	{
		fprintf(stderr,"P(semop); %s\n",strerror(errno));
		exit(1);
	}
}
void D(int semid)
{
	if(semctl(semid,0,IPC_RMID,NULL)<0)
	{
		fprintf(stderr,"semctl2:%s \n",strerror(errno));
		exit(1);
	}
}

