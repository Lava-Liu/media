#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
int main(void)
{
	if(mkfifo("pipe.fifo",0666)<0)
	{
		fprintf(stderr,"mkdido: %s\n",strerror(errno));
		//exit(1);
	}
	int fd=open("pipe.fifo",O_RDONLY);
	if(fd < 0)
	{
		fprintf(stderr,"open :%s\n",strerror(errno));
		exit(1);
	}
	char buffer[256] ={0};
	ssize_t n_read;
	n_read = read(fd,buffer,256);
	if(n_read < 0)
	{
		fprintf(stderr,"read: %s\n",strerror(errno));
		exit(1);
	}
	printf("pipe buffer: %s\n",buffer);
	close(fd);
	return 0;
}
