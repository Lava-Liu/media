#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE (1024*1024)
int main(void)
{
	int fd = open("hole.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
	if(fd < 0)
	{
		fprintf(stderr,"oprn: %s\n",strerror(errno));
		exit(1);
	}
	if(lseek(fd,SIZE-1,SEEK_END)<0)
	{
		fprintf(stderr,"seek: %s\n",strerror(errno));
		exit(1);
	}
	char end = '\0';
	if(write(fd,&end,sizeof(end))!= sizeof(end))
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);
	}

	close(fd);
	return 0;
}
