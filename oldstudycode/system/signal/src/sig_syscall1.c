#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		printf("Get a signal SIGINT \n");
		sleep(5);
		printf("SIGINT handler finished!\n");
	}
}
int main(void)
{
	if(signal(SIGINT,sig_handler)==SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	char buffer[25] = {};

	if(read(STDIN_FILENO,buffer,256)<0)
	
	{
		fprintf(stderr,"read: %s\n",strerror(errno));
		exit(1);
	}
	printf("buffer %s\n",buffer);

	return 0;
}
