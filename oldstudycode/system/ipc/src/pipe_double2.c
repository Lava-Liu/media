#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
int main(void)
{
	int fd[2];
	int fd1[2];
	int fd2[2];
	if(pipe(fd)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
	if(pipe(fd1)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
	if(pipe(fd2)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
	pid_t pid;
	if((pid = fork())<0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else
	if(pid == 0)
	{
		close(fd1[1]);
		close(fd2[0]);
        int num1;
		int num2;
		if(read(fd1[0],&num1,sizeof(num1)) < 0)
		{
			fprintf(stderr,"read: %s\n",strerror(errno));
			exit(1);
		}
		if(read(fd1[0],&num2,sizeof(num2))<0)
		{
			fprintf(stderr,"read: %s\n",strerror(errno));
			exit(1);
		}
		int sum;
		sum=num1+num2;
		if(write(fd2[1],&sum,sizeof(sum))!=sizeof(sum))
		{
			fprintf(stderr,"writre: %s\n",strerror(errno));
			exit(1);
		}

		close(fd1[0]);
		close(fd2[1]);

	}else
	{
		close(fd1[0]);
		close(fd2[1]);
		int num1=1;
		int num2=99;
		if(write(fd1[1],&num1,sizeof(num1))!=sizeof(num1))
		{
			fprintf(stderr,"write: %s\n",strerror(errno));
			exit(1);
		}
		if(write(fd1[1],&num2,sizeof(num2))!=sizeof(num2))
		{
			fprintf(stderr,"write: %s\n",strerror(errno));
			exit(1);
		}
		int ret;
		if(read(fd2[0],&ret,sizeof(ret))<0)
		{
			fprintf(stderr,"read: %s\n",strerror(errno));
			exit(1);
		}
		printf("ret from the pid is: %d\n",ret);
		close(fd1[1]);
		close(fd2[0]);
		wait(NULL);
				

	}
	return 0;
}
