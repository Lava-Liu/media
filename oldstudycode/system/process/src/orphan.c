#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	
	if((pid = fork())< 0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else if(pid == 0)
	{
		sleep(20);
		while(1)
		{

			printf("Pid(%d),PPID :%d,I am still alive!\n",getpid(),getppid());
			sleep(1);
		}
	}else
	{
		printf("Pid: %d,my child is %d\n",getpid(),pid);
		printf("I am going to exit!\n");
		exit(0);
	}
}
