#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
int main(void)
{
	printf("befor,pid %d,ppid: %d,pgid: %d\n",getpid(),getppid(),getpgid(0));
	pid_t pid;
	if( (pid=fork())<0)
	{
	    fprintf(stderr,"fork: %s\n",strerror(errno));
	    exit(1);
	}else if(pid == 0)
	{
	
	if(setsid()<0)
	{
		sleep(2);
		fprintf(stderr,"setsid: %s\n",strerror(errno));

	}
	printf("aafter,pid %d,ppid: %d,pgid: %d\n",getpid(),getppid(),getpgid(0));
	}
	exit(1);
	return 0;
}
