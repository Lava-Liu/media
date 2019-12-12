#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	int fd[2];
	int fd2[2];
	int fd3[2];
    if(pipe(fd)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
    if(pipe(fd2)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
    if(pipe(fd3)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
	int i;
	for(i=0;i<4;i++)
	{
		pid_t pid;
		if((pid = fork())<0)
		{
			fprintf(stderr,"fork : %s\n",strerror(errno));
			exit(1);
		}
		else if(pid == 0)
		{
			if(i == 0) //first process
			{
				close(fd2[0]);
				close(fd2[1]);
				close(fd[0]);
				if(dup2(fd[1],STDOUT_FILENO)<0)
				{
					fprintf(stderr,"dup2: %s\n",strerror(errno));
					exit(1);
				}
				close(fd[1]);
				if(execlp("cat","cat","/etc/passwd",NULL)<0)
				{
					fprintf(stderr,"execlp: %s\n",strerror(errno));
					exit(1);
				}
				
			}
			if(i == 1)//second process
			{
				close(fd[1]);
				close(fd2[0]);
				if(dup2(fd[0],STDIN_FILENO)<0)
				{
					fprintf(stderr,"dup2_2: %s\n",strerror(errno));
					exit(1);
				}
				if(dup2(fd2[1],STDOUT_FILENO)<0)
				{
					fprintf(stderr,"dup2_3: %s\n",strerror(errno));
					exit(1);
				}
				if(execlp("grep","grep","root",NULL)<0)
				{
					fprintf(stderr,"execlp2: %s\n",strerror(errno));
					exit(1);
				}

			}
			if(i == 2)
			{
				close(fd2[1]);
				if(dup2(fd2[0],STDIN_FILENO)<0)
				{
					fprintf(stderr,"dup2: %s\n",strerror(errno));
					exit(1);
				}
				if(execlp("wc","wc","-l",NULL) < 0)
				{
					fprintf(stderr,"execlp3_1: %s\n ",strerror(errno));
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
			if(i == 2)
			{	
				close(fd2[0]);
				close(fd2[1]);
			}
			if(i == 3)
			{	
				close(fd3[0]);
				close(fd3[1]);
			}
			wait(NULL);
			wait(NULL);
			wait(NULL);
			wait(NULL);
		}
	}
}
