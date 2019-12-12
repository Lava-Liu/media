#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		printf("%d receive SIGINT signal \n",getpid());
	}
}
int main(void)
{
	if(signal(SIGINT,sig_handler)==SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);

	}
	pid_t pid;
	if((pid = fork())<0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);

	}
	else if(pid > 0)
	{
		if(kill(pid,SIGINT)<0)
		{
			fprintf(stderr,"kill: %s\n",strerror(errno));
			exit(1);
		}
		//sleep(1);
		raise(SIGINT);
		if(kill(2815,0)==0)
		{
			printf("1 process is exist!\n");
		}
	}
	printf("ppid: %d,pid: %d\n",getppid(),getpid());
	return 0;
}
