#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
int main(void)
{
	//1.建立孤儿进程
	pid_t pid;
	if((pid = fork())<0)
	{
	    fprintf(stderr,"fork: %s\n",strerror(errno));
	    exit(1);
	}else if(pid > 0)
	{
		exit(1);
	}
	//2.修改umask
	umask(0);
	//3.修改路径
	chdir("/");
	//4.创建新的会话
        setsid();
	//5.关闭所有不需要的描述符
	int i;
	int fd = dup(STDIN_FILENO);
	for(i=0;i<=fd;i++)
	{
	    close(i);
	}
	//守护进程创建完毕
	printf("daemon init finished!\n");
	int counter = 0;
	while(1)
	{
		syslog(LOG_DEBUG,"Message from daemon,%d\n",++counter);
		sleep(1);
		if(counter == 10)
			break;
	}
	return 0;
}
