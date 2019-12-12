#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
pid_t third_grop=0;
int main(void)
{
	pid_t pid;
	pid_t first_grop=getpid();
	
	int i;
	for(i=0;i<3;i++)
	{
		if((pid = fork())<0)
		{
			fprintf(stderr,"fork: %s\n",strerror(errno));
			exit(1);
		}else if(pid == 0)
		{
			if(i == 1 && getppid()== first_grop)
			{
				setpgid(0,0);

				break;
			}
			if(i == 1)
			{
				break;
			}

				
			if(i == 2 && getppid()== first_grop)
			{
				setpgid(0,third_grop);

				break;
			}
		}else
		{

			
			if(getppid() == first_grop && (i == 1))
			{
				setpgid(getpid(),getpid());
				setpgid(pid,first_grop);
				break;
			}
			if(getpid() == first_grop && (i==1))
			{
					third_grop=pid;
			}
             

		}
		
	}
	
	printf("pid: %d,ppid: %d,pgid: %d\n",getpid(),getppid(),getpgid(0));
	pause();
	return 0;
}
