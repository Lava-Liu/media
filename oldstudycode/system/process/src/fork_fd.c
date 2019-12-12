#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#define SIZE 4096
int main(void)
{
	int fd = open("fork.txt",O_RDWR|O_CREAT,0666);
	if(fd < 0)
	{
		fprintf(stderr,"open: %s\n",strerror(errno));
		exit(1);
	}
	printf("fd: %d\n",fd);
	pid_t pid;
	pid = fork();
	if(pid < 0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else if(pid > 0)
	{
		char buffer[SIZE]="message by parent!\n";
		size_t len = strlen(buffer);
		if(write(fd,buffer,len)!=len)
		{
			fprintf(stderr,"write: %s\n",strerror(errno));
			exit(1);

		}

	}else
	{
		char buffer[SIZE]="message by child!\n";
		size_t len = strlen(buffer);
		if(write(fd,buffer,len)!=len)
		{
			fprintf(stderr,"write: %s\n",strerror(errno));
			exit(1);

		}


	}
	close(fd);
	pause();
	return 0;
}
