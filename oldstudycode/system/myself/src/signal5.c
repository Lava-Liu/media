#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
void sig_handler(int signo)
{
	static counter=0;
	if(signo == SIGINT)
	{
		printf("receive SIGINT signal!\n");
		counter++;
		printf("counter:%d\n",counter);
		if(counter ==5)
		{
			sigset_t set;
			sigemptyset(&set);
			sigaddset(&set,SIGINT);
			if(sigprocmask(SIG_UNBLOCK,&set,NULL)<0)
			{
				fprintf(stderr,"sig_mask: %s\n",strerror(errno));
				exit(1);
			}
			printf("unblock success!\n");
			signal(SIGINT,SIG_DFL);
			printf("default SIG_INT success!\n");
		}
	}
}

int main(void)
{

	/*sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	if(sigprocmask(SIG_SETMASK,&set,NULL)<0)
	{
		fprintf(stderr,"sig_mask: %s\n",strerror(errno));
		exit(1);
	}*/
	if(signal(SIGINT,sig_handler)<0)
	{
		fprintf(stderr,"sugnal: %s\n",strerror(errno));
		exit(1);
	}
	while(1)
		pause();
	return 0;
}
