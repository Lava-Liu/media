#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	pid_t second_proc;
	pid_t first_proc=getpid();
	int i;
	for(i=0;i<3;i++)
	{
		if((pid=fork())<0)
		{
			fprintf(stderr,"fork: %s\n",strerror(errno));
			exit(1);
		}
	else if(pid == 0)
	{
		sleep(1);
		if(i>=1)
		{
			break;
		}
	}
	else
	{
		if(i==0 && getpid()==first_proc)
		{
			second_proc=pid;
		}
		if(i==1)
		{
			printf("%d\n",second_proc);
		}
		if(getpid()==second_proc )
		{
			printf("%d\n",i);
			printf("%d\n",second_proc);
			break;
		}
	}
    }
	printf("pid: %d,ppid: %d\n",getpid(),getppid());
	pause();
	return 0;
}

