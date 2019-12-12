#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


//cat /etc/passwd | grep root


int main(void)
{
	int fd[2];
	if(pipe(fd)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
	int i;
	pid_t pid;
	for(i=0;i<2;i++)
	{
		pid = fork();
		if(pid < 0)
		{
			fprintf(stderr,"fork %s\n",strerror(errno));
			exit(1);
		}
	    else if(pid == 0)
		{
			if(i ==0)
			{
				close(fd[0]);
				if(dup2(fd[1],STDOUT_FILENO)<0)
				{
			       fprintf(stderr,"fork1 %s\n",strerror(errno));
			       exit(1);
				}
				if(execlp("cat","cat","/etc/passwd",NULL)<0)
				{
					fprintf(stderr,"exec: %s\n",strerror(errno));
					exit(1);
				}
			}
			if(i == 1)
			{
				close(fd[1]);
				if(dup2(fd[0],STDIN_FILENO)<0)
				{
			       fprintf(stderr,"fork %s\n",strerror(errno));
			       exit(1);
				}
				
				if(execlp("grep","grep","root",NULL)<0)
				{
					fprintf(stderr,"exec: %s\n",strerror(errno));
					exit(1);
				}

			}
			break;
		}else
		{
			if(i == 1)
			{
			  close(fd[0]);
			   close(fd[1]);
			}
			wait(NULL);
			wait(NULL);
		}

	}
	return 0;
}

