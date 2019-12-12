#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void out_status(int status)
{
	if(WIFEXITED(status))
	{
		printf("normal exited,status code : %d\n",
				WEXITSTATUS(status));
	}else if(WIFSIGNALED(status))
	{
		printf("Siganal exited,signal number: %d\n",WTERMSIG(status));
	}
	else if(WIFSTOPPED(status))
	{
		printf("stopped exited,stop code: %d\n",WSTOPSIG(status));
	}
	else
	{
		printf("unknow wxited\n");
	}
}
int main(void)
{
	int status;
	pid_t pid;
	if((pid = fork())<0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else if(pid ==0)
	{
		exit(77);
	}
	//调用wait 进程进入阻塞状态
	//等待SIGCHLD信号
	//收到SIGCHLD信号后，回收相关的子进程状态
	//并从wait函数返回对应的子进程PID
	//每次只能处理一个子进程*
	if(wait(&status)== pid)
	{
		out_status(status);
	}
	if((pid = fork())< 0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);

	}else if(pid ==0)
	{   //6
		abort();//通过SIGABRT信号异常退出
	}
	if(wait(&status)== pid)
	{
		out_status(status);
	}


	if((pid = fork())< 0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);

	}else if(pid ==0)
	{
		printf("Pid: %d,please kill me\n",getpid());
		pause();

	}
	if(wait(&status)== pid)
	{
		out_status(status);
	}


	return 0;
}

