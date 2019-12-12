#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		printf("receive a SIGINT signal!\n");
		sleep(1);
		printf("SIGINT handle finished!\n");
	}
}
int main(void)
{
	if(signal(SIGINT,sig_handler)==SIG_ERR)
	{
		fprintf(stderr,"read: %s\n",strerror(errno));
		exit(1);

	}
	char buffer[256]={};
	ssize_t n_read = 0;
	if((n_read=read(STDIN_FILENO,buffer,256))<0)
	{
		fprintf(stderr,"read: %s\n",strerror(errno));
		exit(1);
	}
	printf("read success :");
	if(write(STDOUT_FILENO,buffer,n_read) != n_read)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);

	}

	return 0;
}
