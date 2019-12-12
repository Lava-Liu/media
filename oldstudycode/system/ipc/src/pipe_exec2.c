#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	int fd[2];
	if(pipe(fd)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
	pid_t pid;
	int i;
	for(i=0;i<2;i++)
	{
		if((pid = fork()) < 0)
		{
			fprintf(stderr,"fork: %s\n",strerror(errno));
			exit(1);
		}else if(pid == 0)
		{
			if(i == 0)
			{
				close(fd[0]);
				dup2(fd[1],STDOUT_FILENO);
				close(fd[1]);
				if(execlp("cat","cat","/etc/passwd",NULL)<0)
				{
					fprintf(stderr,"exec: %s\n",strerror(errno));
					exit(1);
				}
			}
			if(i == 1)
			{
				close(fd[1]);
				dup2(fd[0],STDIN_FILENO);
				close(fd[0]);
				if(execlp("grep","grep","root",NULL)<0)
				{
					fprintf(stderr,"exec: %s\n",strerror(errno));
					exit(1);
				}
			}
		}else
		{
			if(i==1)
			{
				close(fd[1]);
				close(fd[2]);
				wait(NULL);
				wait(NULL);
			}
		}
	}
	return 0;
}
