#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define MAX_SIZE 4096
int main(void)
{
	int fd = dup(STDOUT_FILENO);
	if(fd < 0)
	{
		fprintf(stderr,"dup: %s\n",strerror(errno));
		exit(1);
	}
	printf("fd: %d\n",fd);
	char buffer[]= "my name is liuwei !\n";
	size_t size = strlen(buffer);
	if(write(fd,buffer,size)!=size)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);
	}
	close(fd);

	int fda = open("/etc/passwd",O_RDONLY);
	if(fda < 0)
	{
		fprintf(stderr,"open: %s\n",strerror(errno));
		exit(1);
	}
	int fdb = dup(fda);
	if( fdb < 0)
	{
		fprintf(stderr,"dup: %s\n",strerror(errno));
		exit(1);
	}
	char buf[MAX_SIZE] = {};
	ssize_t n_read = 0;

	n_read = read(fda,buf,100);

	printf("fda:\n");
	write(STDOUT_FILENO,buf,n_read);

	n_read = read(fdb,buf,100);
	printf("fdb:\n");
	write(STDOUT_FILENO,buffer,n_read);
	close(fda);
	close(fdb);

	return 0;
}
