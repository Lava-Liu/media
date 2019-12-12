#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/shm.h>
#include "tell.h"
int main(void)
{
	int shmid;
	if((shmid = shmget(IPC_PRIVATE,1024,IPC_CREAT|IPC_EXCL|0777))<0)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);
	}
	init();
	pid_t pid;
	if((pid = fork())<0)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);
	}else if(pid > 0)
	{
		int *pi=(int *)shmat(shmid,0,0);
		if(pi == (int *)-1)
		{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);

		}
		*pi = 100;
		*(pi + 1) = 200;
		shmdt(pi);
		notify_pipe();
		destroy_pipe();

	}else
	{
		wait_pipe();
		int *pi =(int *)shmat(shmid,0,0);
		if(pi == (int *)-1)
		{

		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);
		}
		printf("start: %d end : %d\n",*pi,*(pi+1));
		shmdt(pi);
		shmctl(shmid,IPC_RMID,NULL);
		destroy_pipe();
	}
	return 0;
}
