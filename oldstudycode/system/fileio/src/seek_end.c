#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"-Usage: %s [filename]\n",argv[0]);
		exit(1);
	}
	int fd = open("a.txt",O_WRONLY|O_CREAT|O_APPEND,0666);
		if(fd < 0)
	{
		fprintf(stderr,"open: %s \n",strerror(errno));
		exit(1);

	}	
	if(lseek(fd,0,SEEK_END)<0)
	{
		fprintf(stderr,"lseek: %s\n",strerror(errno));
		exit(1);

	}
	sleep(10);
	size_t len = strlen(argv[1]);
	if(write(fd,argv[1],len)!=len)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);

	}
	close(fd);

	return 0;
}
