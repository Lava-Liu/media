#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	char *cmds[]=
	{
		"cat /etc/passwd",
		"head -5",
		"grep sh",
		"wc -l"

	};
	int cmds_len = sizeof(cmds)/sizeof(cmds[0]);
	pid_t pid;
	int pre_fd;
	int fd[2];
	int i=0;
	for(i;i<cmds_len;i++)
	{
		if(i<cmds_len-1)
		{
			if(pipe(fd)<0)
			{
				fprintf(stderr,"pipe: %s\n",strerror(errno));
				exit(1);
			}

		}
		pid =fork();
		if(pid < 0)
		{
			fprintf(stderr,"fork: %s\n",strerror(errno));
			exit(1);
		}
		else if(pid == 0)
		{
			if(i == 0)
			{
				close(fd[0]);
				if(dup2(fd[1],STDOUT_FILENO)<0)
				{
					fprintf(stderr,"dup2: %d:%s\n",i,strerror(errno));
					exit(1);
				}
				close(fd[1]);
			}else if(i < cmds_len -1)
			{
				close(fd[0]);
				if(dup2(pre_fd,STDIN_FILENO)<0)
				{
					fprintf(stderr,"dup2: %d:%s\n",i,strerror(errno));
					exit(1);
				}
				if(dup2(fd[1],STDOUT_FILENO)<0)
				{
					fprintf(stderr,"dup2: %d:%s\n",i,strerror(errno));
					exit(1);
				}
				close(pre_fd);
				close(fd[1]);

			}else
			{
				if(dup2(pre_fd,STDIN_FILENO)<0)
				{
					fprintf(stderr,"dup2: %d:%s\n",i,strerror(errno));
					exit(1);
				}
			}

			if(execlp("bash","bash","-c",cmds[i],NULL)<0)
			{
				fprintf(stderr,"exec: %s\n",strerror(errno));
				exit(1);
			}
		}else
		{
			//保存当前管道的读端
			//供下一个进程读取数据
			//
			if(i < cmds_len-1)
			{
				pre_fd=dup(fd[0]);
				if(pre_fd < 0)
				{
					fprintf(stderr,"dup_back: %d:%s\n",i,strerror(errno));
					exit(1);
			    }
			}
			close(fd[0]);
			close(fd[1]);
			wait(NULL);
		}
	}
}
