#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

static pid_t pids[1024];
FILE *mpopen(char *cmd,char *mode)
{

	int fd[2];
	pid_t pid;
	if(pipe(fd)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
	}
	if((pid = fork())<0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else if(pid == 0)
	{
	
		if(!strcmp(mode,"r"))
		{
			close(fd[0]);
			dup2(fd[1],STDOUT_FILENO);
			close(fd[1]);
		}
		if(!strcmp(mode,"w"))
		{
			close(fd[1]);
			dup2(fd[0],STDIN_FILENO);
			close(fd[0]);
		}
		    if(execlp("/bin/bash","/bin/bash/","-c",cmd,NULL)<0)
			{
				fprintf(stderr,"execlp: %s\n",strerror(errno));
				exit(1);
			}
	}else
	{
		if(!strcmp(mode,"r"))
		{
			close(fd[1]);
			FILE *fp;
			pids[fd[0]]=pid;
			fp = fdopen(fd[0],"r");
			return fp;
		}
		if(!strcmp(mode,"w"))
		{
			close(fd[0]);
			FILE *fp;
			pids[fd[1]]=pid;
			fp = fdopen(fd[1],"w");
			return fp;
		}

	}
}
void mpclose(FILE *fp)
{
	int fd = fileno(fp);
	wait(pids[fd]);
	fclose(fp);
}
int main(void)
{
	FILE *fp;
	FILE *fp2;
	fp = mpopen("cat /etc/passwd |wc -l","r");
    fp2 = mpopen("wc -l","w");
    fprintf(fp2,"1\n2\n3\n");
	int num;
	fscanf(fp,"%d",&num);
	printf("%d\n",num);
	mpclose(fp);
	return 0;
}
