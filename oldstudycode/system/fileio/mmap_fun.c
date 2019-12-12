#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"usage:%s [File name]\n",argv[0]);
		exit(1);
	}
	int fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		fprintf(stderr,"Open: %s\n",strerror(errno));
		exit(1);
	}
	ssize_t len = lseek(fd,0,SEEK_END);
	int (*fp)(int,int )=mmap(NULL,len,PROT_EXEC,MAP_SHARED,fd,0);
	if(fp == MAP_FAILED)
	{
		fprintf(stderr,"mmap: %s\n",strerror(errno));
		exit(1);

	}
	int ret = fp(10,20);
	printf("%d\n",ret);
    if(munmap(fp,len)<0)
	{
		fprintf(stderr,"munmap: %s\n",strerror(errno));
		exit(1);

	}

	return 0;
}
