#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main(void)
{
	pid_t pid;
	if((pid=fork())<0)
	{
		
		fprintf(stderr,"fore : %s\n",strerror(errno));
		exit(1);
	}else if(pid == 0)
	{
		printf("chaild: %d started!\n",getpid());
		sleep(10);
		printf("child: %d I am over!\n",getpid());
		exit(0);
	}else
	{
		printf("parent: %d started!\n",getpid());
		printf("Watiing for SIGCHLD!\n");
		pid_t re_pid=wait(NULL);
		printf("wait finished!, %d is comed!\n",re_pid);
		pause();
	}
	return 0;
}
