#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int signo)
{
	if(signo == SIGALRM)
	{
		printf("timeout\n");
	}
}
int main(void)
{
	if(signal(SIGALRM,sig_handler)== SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	alarm(10);
	while(1)
		pause();
	return 0;
}
