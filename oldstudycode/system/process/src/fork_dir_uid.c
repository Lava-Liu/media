#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	printf("cwd befor fork : %s\n",getcwd(NULL,0));
	pid_t pid;
	pid = fork();
	if(pid < 0)
	{
		fprintf(stderr,"fprk : %s\n",strerror(errno));
		exit(1);
	}else if(pid > 0)
	{
		chdir("/");
 	    printf("cwd befor fork :%d %s\n",getpid(),getcwd(NULL,0));
		printf("uid %d, euid %d \n",getuid(),geteuid());
		printf("uid %d, euid %d \n",getgid(),getegid());
	}else
	{
		sleep(5);
		printf("child：\n");
	    printf("cwd befor fork :%d %s\n",getpid(),getcwd(NULL,0));
		printf("uid %d, euid %d \n",getuid(),geteuid());
		printf("uid %d, euid %d \n",getgid(),getegid());

	}
	pause();
	return 0;
}
