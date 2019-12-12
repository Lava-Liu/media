#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_SIZE 4096
void copy(int fd1,int fd2)
{
	char buffer[MAX_SIZE]={};
	ssize_t n_read=0;
	while((n_read=read(fd1,buffer,MAX_SIZE))!=0)
	{
		if(write(fd2,buffer,n_read)!=n_read)
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
}
int main(int argc,char *argv[])
{
	int i=1;
	for(i=1;i<argc;i++)
	{

		if(!strcmp(argv[i],"+"))
		{
			i++;
			if(i>=argc)
			{
				fprintf(stderr,"Less arg for + \n");
				exit(1);
			}
			int fd = open(argv[i],O_RDONLY);
			if(fd < 0)
			{
				fprintf(stderr,"openfd: %s\n",strerror(errno));
				exit(1);
			}
			int fd_in=dup2(fd,STDIN_FILENO); 
			if(fd_in < 0)
			{
				fprintf(stderr,"fd_in: %s\n",strerror(errno));
				exit(1);
			}
			close(fd);

		}else if(!strcmp(argv[i],"-"))
		{
			i++;
			if(i>=argc)
			{
				fprintf(stderr,"Less arg for - \n");
				exit(1);
			}
			int fd2 = open(argv[i],O_WRONLY|O_CREAT|O_TRUNC,0666);
			if(fd2 < 0)
			{
				fprintf(stderr,"openfd2: %s\n",strerror(errno));
				exit(1);
			}
			int fd_out=dup2(fd2,STDOUT_FILENO); 
			if(fd_out < 0)
			{
				fprintf(stderr,"fd_out: %s\n",strerror(errno));
				exit(1);
			}
			close(fd2);
		}else if(!strcmp(argv[i],"2-"))
		{
			i++;
			if(i>=argc)
			{
				fprintf(stderr,"Less arg for 2- \n");
				exit(1);
			}
			int fd3 = open(argv[i],O_WRONLY|O_CREAT|O_TRUNC,0666);
			if(fd3 < 0)
			{
				fprintf(stderr,"openfd3: %s\n",strerror(errno));
				exit(1);
			}
			int fd_err=dup2(fd3,STDERR_FILENO); 
			if(fd_err < 0)
			{
				fprintf(stderr,"fd_err: %s\n",strerror(errno));
				exit(1);
			}
			close(fd3);
		}else if(!strcmp(argv[i],"--"))
		{
			i++;
			if(i>=argc)
			{
				fprintf(stderr,"Less arg for -- \n");
				exit(1);
			}
			int fd4 = open(argv[i],O_WRONLY|O_CREAT|O_APPEND,0666);
			if(fd4 < 0)
			{
				fprintf(stderr,"openfd4: %s\n",strerror(errno));
				exit(1);
			}
			int fd_ped=dup2(fd4,STDOUT_FILENO); 
			if(fd_ped < 0)
			{
				fprintf(stderr,"fd_ped: %s\n",strerror(errno));
				exit(1);
			}
			close(fd4);



		
	}
	}
	copy(STDIN_FILENO,STDOUT_FILENO);
	return 0;
}
