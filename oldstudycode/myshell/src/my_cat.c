#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define SIZE 4096
void copy(int fd1,int fd2)
{
	char *buffer[SIZE];
	ssize_t n_read;
	while((n_read=read(fd1,buffer,SIZE))!=0)
	{
		if(n_read < 0)
		{
			fprintf(stderr,"read: %s\n",strerror(errno));
			exit(1);
		}
		if(write(fd2,buffer,n_read)!=n_read)
		{
			fprintf(stderr,"write: %s\n",strerror(errno));
			exit(1);
		}
	}
}
int main(int argc,char *argv[])
{
	int x = argc-1;
	int i=1;
	while(x!=0)
	{
		if(!strcmp(argv[i],"<"))
		{
			i++;
			int fd;
			if((fd=open(argv[i],O_RDONLY|O_CREAT,0666))<0)
			{
				fprintf(stderr,"open: %s\n",strerror(errno));
				exit(1);
			}
			dup2(fd,STDIN_FILENO);
		}
		else if(!strcmp(argv[i],">"))
		{
			i++;
			int fd2;
			if((fd2=open(argv[i],O_RDWR|O_CREAT,0666))<0)
			{
				fprintf(stderr,"open: %s\n",strerror(errno));
				exit(1);
			}
			dup2(fd2,STDOUT_FILENO);
		}else
		{
			int fd3;
			if((fd3=open(argv[i],O_RDONLY|O_CREAT,0666))<0)
			{
				fprintf(stderr,"open3: %s\n",strerror(errno));
				exit(1);
			}
			dup2(fd3,STDIN_FILENO);
		}
		x--;
	}
	copy(STDIN_FILENO,STDOUT_FILENO);

	return 0;
}
