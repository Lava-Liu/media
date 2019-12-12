#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		printf("%d received a SIGINT signal!\n",getpid());

	}else if(signo == SIGCHLD)
	{
		printf("%d receiced a SIGCHLD signal!\n",getpid());
		wait(NULL);
	}
}
int main(void)
{
	if(signal(SIGINT,sig_handler)== SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	if(signal(SIGCHLD,sig_handler)==SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
		
	}
	pid_t pid;
	int i;
	for(i=0;i<3;i++)
	{
	if((pid = fork())<0)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);

	}
	}
	printf("PPID: %d pid: %d\n",getppid(),getpid());
	while(1)
	{
		pause();
	}

	return 0;
}
