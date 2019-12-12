#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{   //1创建管道    pipe
	//2创建子进程  fork
	//3关闭不使用管道 close
	//4数据传输    read,write
	//5关闭剩余管道 close
	int fd[2];
	if(pipe(fd)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
	pid_t pid;
	if((pid = fork())< 0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));

		exit(1);
	}
	else if(pid == 0)//child process
	{
		close(fd[1]);
		int num_ch;
		read(fd[0],&num_ch,sizeof(num_ch));
		printf("num from parent: %d\n",num_ch);
		close(fd[0]);
		
	}else//parent process
	{
		close(fd[0]);
		int num = 123;
		write(fd[1],&num,sizeof(num));
		close(fd[1]);
		wait(NULL);
	}
	
	return 0;
}
