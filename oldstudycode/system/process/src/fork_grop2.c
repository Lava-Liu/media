#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	pid_t pid;
	int i;
	int first_pid=getpid();
	printf("pid:%d,PGID:%d\n",getpid(),getpgid(0));
	for(i =0;i<4;i++)
	{
		if((pid= fork())<0)
		{
			fprintf(stderr,"fork: %s\n",strerror(errno));
			exit(1);
		}else if(pid == 0)
		{
			printf("pid:%d,PGID:%d,PPID%d\n",getpid(),getpgid(0),getppid());
			break;
		}else
		{
			if(i == 0)
			{
				  setpgid(pid,pid);
				  first_pid=pid;
			}else
			{
				setpgid(pid,first_pid);
			}
		}
	}
	pause();
	return 0;
}
