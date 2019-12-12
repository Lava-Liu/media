#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
void sig_handler(int signo)
{
	if(signo == SIGALRM)
	{
		printf("the alarm is already reveive !\n");
	}
}
int main(void)
{
	if(signal(SIGALRM,sig_handler)==SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	alarm(10);
	while(1)
		pause();

}
