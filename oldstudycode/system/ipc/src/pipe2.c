#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
int main(void)
{
	int fd[2];
	if(pipe(fd)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
	pid_t pid;
	if((pid=fork())<0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else if(pid == 0)
	{
		close(fd[1]);
		int num;
		if(read(fd[0],&num,sizeof(num))<0)
		{
			fprintf(stderr,"readL %s\n",strerror(errno));
			exit(1);
		}
		printf("num from parent: %d\n",num);
		close(fd[0]);
	}else
	{
		close(fd[0]);
		int number=99;
		if(write(fd[1],&number,sizeof(number))!=sizeof(number))
		{
			fprintf(stderr,"write: %s\n",strerror(errno));
			exit(1);
		}
		close(fd[1]);
		wait(NULL);
	}
	return 0;
}
