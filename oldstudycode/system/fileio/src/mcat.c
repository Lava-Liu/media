#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#define MAX_SIZE 4096
/*void copy(int  fd1,int fd2)
{
	char buffer[MAX_SIZE] = {};
	size_t n_read=0;
	while((n_read=read(fd1,buffer,MAX_SIZE))!=0)
	{
		if(write(fd_out,buffer,n_read)!=n_read)
		{

		}
	}
}*/
int main(int argc,char *argv[])
{
	

	int fd = open(argv[2],O_RDONLY|O_CREAT|O_TRUNC,0666);
	//int fd2 = open(argv[4],O_WRONLY|O_CREAT|O_TRUNC,0666);
	
	if(fd < 0)
	{
		fprintf(stderr,"open %s\n",strerror(errno));
		exit(1);
	}
	/*if(fd2 < 0)
	{
		fprintf(stderr,"open2 %s\n",strerror(errno));
		exit(1);
	}*/
	if(strcmp("+",argv[1])==0)
	{
	int fd_dup = dup2(fd,STDOUT_FILENO);
	if(fd_dup < 0)
	{
		fprintf(stderr,"dup2 %s\n",strerror(errno));
		exit(1);
	}
	}
	/*
	if(strcmp(argv[1],"-")==1 )
	{
	int fd_dup2 = dup2(fd2,STDIN_FILENO);
	if(fd_dup2 < 0)
	{
		fprintf(stderr,"dup2 %s\n",strerror(errno));
		exit(1);
	}
	}
	
	if(strcmp(argv[3],"-")==1)
	{
	int fd_dup3 = dup2(fd2,STDOUT_FILENO);
	if(fd_dup3 < 0)
	{
		fprintf(stderr,"dup2 %s\n",strerror(errno));
		exit(1);
	}

	}*/
	//close(fd2);
	close(fd);
	
	return 0;
}
