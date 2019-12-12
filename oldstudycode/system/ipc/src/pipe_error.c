#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
int set_fl(int fd ,int flag)
{
	int old_flag;
	old_flag =fcntl(fd,F_GETFL);
	int newflag = old_flag | flag;

	return fcntl(fd,F_SETFL,newflag);
}
void sig_handler(int signo)
{
	if(signo == SIGPIPE)
	{
		printf("%d receive SIGEPIPE!\n",getpid());
	}
}

int main(void)
{//绑定信号
	if(signal(SIGPIPE,sig_handler)!=0)
	{
		fprintf(stderr,"signal %s\n",strerror(errno));
		exit(1);
	}
	//建立管道
	int fd[2];
	if(pipe(fd)<0)
	{
		fprintf(stderr,"pipe %s\n",strerror(errno));
		exit(1);

	}

	//设置非阻塞属性
	if(set_fl(fd[0],O_NONBLOCK)<0)
	{
		fprintf(stderr,"set_fl %s\n",strerror(errno));
		exit(1);
	}
	if(set_fl(fd[1],O_NONBLOCK)<0)
	{
		fprintf(stderr,"set_fl %s\n",strerror(errno));
		exit(1);
	}

	//创建子进程
	pid_t pid;
	if((pid = fork())<0)
	{
		fprintf(stderr,"fork %s\n",strerror(errno));
		exit(1);

	}else if(pid == 0)
	{
		close(fd[0]);
		close(fd[1]);
		/*int counter = 0;
		while(1)
		{
			if(write(fd[1],"a",1) !=1)
			{
				break;
			}
			counter++;
			printf("%d\n",counter);
		}
		printf("Already written %d\n",counter);*/

	}else
	{
		//close(fd[1]);
		wait(NULL);
		
		/*close(fd[0]);
		char *str = "message";
		int len = strlen(str);
		int n_write;
		if((n_write=write(fd[1],str,len))!=len)
		{
			fprintf(stderr,"write %s\n",strerror(errno));
		}
		printf("write success!%d\n",n_write);*/
		close(fd[1]);
		char buffer[256];
		ssize_t n_read;
		n_read=read(fd[0],buffer,256);
		printf("nread: %d\n",n_read);
	}
	return 0;
}
