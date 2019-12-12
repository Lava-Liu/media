#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
void sig_handler(int signo)
{
	if(signo == SIGCHLD)
	{
		printf("reveive SIGCHLD signal!\n");
		pid_t pid;
	    while(1)
		{
			pid = waitpid(-1,NULL,WNOHANG);
			if(pid <= 0)
			{
				break;
			}
	
			printf("child %d is waited!\n",pid);
		}

		wait(NULL);
	}
}
int main(void)
{
	pid_t pid;
	if(signal(SIGCHLD,sig_handler)==SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	int i;
	for(i=0;i<5;i++)
	{
		if( (pid=fork()) < 0)
		{
			fprintf(stderr,"fork: %s\n",strerror(errno));
			exit(1);
		}
		if(pid == 0)
	    {
		    break;
		}
		else
		{
		

		}
		
		
	}
	printf("pid: %d,ppid : %d pgid: %d\n",getpid(),getppid(),getpgid(0));
		


	return 0;	
}
