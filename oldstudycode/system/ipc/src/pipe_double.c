#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>

int main(void)
{
	int fd[2];
	int fd_new[2];
	if(pipe(fd)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
	if(pipe(fd_new)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
	pid_t pid;
	if((pid = fork())< 0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);

	}else if(pid == 0)
	{
		close(fd[1]);
		close(fd_new[0]);
		ssize_t n_read;
		int num1_ch,num2_ch,sum_ch;
		n_read = read(fd[0],&num1_ch,sizeof(num1_ch));
		printf("child,n_read %d\n",num1_ch);
		n_read = read(fd[0],&num2_ch,sizeof(num2_ch));
		printf("child,n_read %d\n",num2_ch);
		sum_ch =num1_ch +num2_ch;
		write(fd_new[1],&sum_ch,sizeof(sum_ch));
		close(fd[0]);
		close(fd_new[1]);
	}else
	{
		close(fd[0]);
		close(fd_new[1]);
		//fd 写管道
		//fd_new 读管道
		ssize_t n_read;
		int num1=123,num2=321,sum;
		if(write(fd[1],&num1,sizeof(num1))!=sizeof(num1))
		{
		  fprintf(stderr,"pipe: %s\n",strerror(errno));
		  exit(1);
		}
		if(write(fd[1],&num2,sizeof(num2))!=sizeof(num2))
		{
		   fprintf(stderr,"pipe: %s\n",strerror(errno));
		    exit(1);
		}
		n_read =read(fd_new[0],&sum,sizeof(sum));
		printf("parent,n_read %d\n",sum);
		close(fd[1]);
		close(fd_new[0]);
		wait(NULL);
	}
}
