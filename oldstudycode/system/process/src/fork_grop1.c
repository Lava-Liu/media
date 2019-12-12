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
	for(i =0;i<3;i++)
	{
		if((pid= fork())<0)
		{
			fprintf(stderr,"fork: %s\n",strerror(errno));
			exit(1);
		}else if(pid == 0)
		{
			setpgid(getpid(),first_pid);
			if(getppid()==first_pid)
			{
				if(setpgid(getpid(),getpid())<0)
				{
					fprintf(stderr,"setpgid: %s \n",strerror(errno));
					exit(1);
				}

			}
			printf("pid:%d,PGID:%d\n",getpid(),getpgid(0));
		}else
		{

		break;
		}
	}
	pause();
	return 0;
}
