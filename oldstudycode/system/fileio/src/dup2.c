#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	int fd = open("dup.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
	if(fd < 0)
	{
		fprintf(stderr,"open %s\n",strerror(errno));
		exit(1);
	}
	int fd_dup = dup2(fd,STDOUT_FILENO);
	if(fd_dup < 0)
	{
		fprintf(stderr,"dup2 %s\n",strerror(errno));
		exit(1);
	}
	fprintf(stderr,"fd_dup: %d\n",fd_dup);
	printf("this is stdout message!\n");
	close(fd);
	
	return 0;
}
