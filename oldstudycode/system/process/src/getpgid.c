#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main(void)
{
	pid_t  pid;
	if((pid= fork())< 0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}
	else if(pid == 0)
	{
		printf("pid: %d,ppid: %d,pgid: %d\n",getpid(),getppid(),getpgrp());
		if(setpgid(0,0)<0)
		{
			fprintf(stderr,"setpgid: %s\n",strerror(errno));
			exit(1);
		}
		printf("pid: %d,ppid: %d,pgid: %d\n",getpid(),getppid(),getpgrp());

	if((pid= fork())< 0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}
	else if(pid == 0)
	{
		printf("pid: %d,ppid: %d,pgid: %d\n",getpid(),getppid(),getpgrp());

		exit(0);
	}
		wait(NULL);

		exit(0);
	}
		printf("pid: %d,ppid: %d,pgid: %d\n",getpid(),getppid(),getpgrp());
		wait(NULL);


	return 0;
}
