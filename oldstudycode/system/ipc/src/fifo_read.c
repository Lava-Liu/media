#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"USage %s fifo\n",argv[0]);
		exit(1);
	}
	int fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		fprintf(stderr,"open : %s\n",strerror(errno));
		exit(1);
	}else
	{
		printf("open success %d\n",fd);
	}
	char buffer[30];
	if(read(fd,buffer,30)<0)
	{
		fprintf(stderr,"read : %s\n",strerror(errno));
		exit(1);

	}else
	{
		printf("%s\n",buffer);
	}
	close(fd);
	return 0;
}

