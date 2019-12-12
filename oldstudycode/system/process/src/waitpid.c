#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	int i;
	for(i=0;i<3;i++)
	{
		if((pid=fork())<0)
		{
			fprintf(stderr,"fork : %s\n",strerror(errno));
			exit(1);
		}else if(pid == 0)
		{
			printf("%d started!\n",getpid());
			sleep(10+i);
			exit(0);
		}
	}
		while(1)
		{
			pid_t re_pid = waitpid(-1,NULL,1);
			if(re_pid == 0)
			{
				printf("No child process is over!\n");
			}	   
			else if(re_pid > 0)
			{
				printf("%d is over!\n",re_pid);
			}else
			{
				fprintf(stderr,"waitpid %s",strerror(errno));
				printf("None child left to wait!\n");
				break;
			}
			sleep(1);
		
		}
	
	return 0;
}
