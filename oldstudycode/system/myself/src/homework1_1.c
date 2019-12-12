/*用read_write实现mcp*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 256
int main(int argc,char*argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"-Useage %s [filename] [filename]\n",argv[0]);
		exit(1);
	}
	int fd = open(argv[1],O_RDONLY);
	int fd2 = open(argv[2],O_WRONLY);
	if( fd < 0 || fd2 < 0)
	{
		fprintf(stderr,"Open: %s\n",strerror(errno));
		exit(1);
    }

    char buffer[MAX_SIZE]={};
	size_t n_read=0;
	while((n_read=read(fd,buffer,MAX_SIZE))>0)
	{
		size_t size=strlen(buffer);
		if(write(fd2,buffer,size)!=size)
		{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);
		}

	}
	if(n_read < 0)
	{
		fprintf(stderr,"read: %s\n",strerror(errno));
		exit(1);

	}	
    close(fd2);
	close(fd);
	return 0;
}

