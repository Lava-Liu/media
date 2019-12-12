#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		printf("SIGINT signal received!\n");
		if(execl("./bin/sig_handler","/bin/sig_handler",NULL)<0)
		{
			fprintf(stderr,"exec: %s\n",strerror(errno));
			exit(1);
		}
		printf("exec success!\n");
	}
}
int main(void)
{	if(signal(SIGINT,sig_handler)== SIG_ERR)
	{
			fprintf(stderr,"signal: %s\n",strerror(errno));
			exit(1);

	}
	printf("wait for SIGINT signal!\n ");
    while(1);
	return 0;
}
