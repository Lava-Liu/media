#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	pid_t  pid;
	printf(" buffer ");
	pid = fork();
	
	if(pid < 0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else if(pid > 0)
	{
		printf("parent %d\n",getpid());
	}
	else
	{
		sleep(5);
		printf("child %d\n",getpid());
	}
	pause();

	return 0;
}
