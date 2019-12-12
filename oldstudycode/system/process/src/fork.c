#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
int main(void)
{
	pid_t pid;
	pid = vfork();
	if(pid < 0)
	{
		fprintf(stderr,"fork : %s\n",strerror(errno));
		exit(1);
	}else if(pid > 0)//parent
	{
		printf("I am parent: %d\n",getpid());
	}else //child
	{
		printf("I am child: %d\n",getpid());
		sleep(5);
		_exit(0);
		
	}
	printf("pid: %d\n",pid);
	printf("pid: %d\n",getpid());
	
	return 0;
}
