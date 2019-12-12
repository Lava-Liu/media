#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define MAX_SIZE 256
int main(void)
{
	int fd = open("/etc/passwd",O_RDONLY);
	if( fd < 0)
	{
		fprintf(stderr,"Open: %s\n",strerror(errno));
		exit(1);
	}
	char buffer[MAX_SIZE] = {};
	ssize_t n_read = 0;
	while((n_read = read(fd,buffer,MAX_SIZE-1))>0)
	{
		printf("Buffer: %s\n",buffer);
		buffer[n_read] = '\0';

	}
	if(n_read<0)
	{
		fprintf(stderr,"Read: %s\n",strerror(errno));
		exit(1);
	}
	close(fd);

	int fd2 = open("out.txt",O_WRONLY);
	if(fd2<0)
	{
		fprintf(stderr,"Open: %s\n",strerror(errno));
		exit(1);
	}
	char str[] = "out message!\n";
	ssize_t size = strlen(str);
	if(write(fd2,str,size) != size)
	{
		fprintf(stderr,"Write:%s\n",strerror(errno));
		exit(1);
	}
	close(fd2);
	return 0;
}
