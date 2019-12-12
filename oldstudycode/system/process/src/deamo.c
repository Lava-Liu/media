#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
int main(void)
{
	pid_t pid;
	if((pid = fork())<0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else if(pid >0)
	{
		exit(0);

	}
	umask(0);
	chdir("/");
	int i;
	for(i = 0;i < 3;i++)
	{
		close(i);
	}
	//5、建立新的会话
	setsid();
	//开始守护进程的工作
	syslog(LOG_DEBUG,"pid : %d,ppid: %d,pgid: %d\n",getpid(),getppid(),getpgid(0));
	int counter = 0;
	while(1)
	{
		syslog(LOG_DEBUG,"this is out by daemon: %d\n",counter++);
		sleep(5);
	}

	
	return 0;
}
