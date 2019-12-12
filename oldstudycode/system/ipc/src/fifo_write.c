#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"usage %s fifo\n",argv[0]);
		exit(1);
	}
	int fd = open(argv[1],O_WRONLY);
	if(fd < 0)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);
	}else
	{
		printf("open success %d\n",fd);
	}
	char *s = "123456";
	if(write(fd,s,strlen(s))!=strlen(s))
	{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);
	}
	close(fd);
	return 0;
}
