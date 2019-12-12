#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	pid_t first_pid=getpid();
	int i;
	for(i=0;i<3;i++)
	{
	if((pid=fork())<0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else if(pid == 0)
	{
		if(i == 0)
		{
			break;
		}
		if(i == 2)
		{
			break;
		}
	}else
	{
		if(getppid() ==first_pid && i ==2 )
		{
			break;
		}
	}
	}
	printf("pid: %d,ppid: %d\n",getpid(),getppid());
	pause();
	return 0;
}
