#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	printf("Cur fore GID: %d\n",tcgetpgrp(0));
	pid_t pid;
	if((pid= fork())<0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else if(pid == 0)
	{
	    printf("Cur fore GID: %dbefor change!\n",tcgetpgrp(0));
		setpgid(0,0); //独立一个进程组
		printf("I am child %d,at group %d\n",getpid(),getpgid(0));
		/*if(tcsetpgrp(0,getpgid(0))<0)
		{
			fprintf(stderr,"tcsetpgid: %s\n",strerror(errno));
			exit(1);
		}*/
		pause();
		exit(0);
	}
	printf("I am parent %d,at grop %d\n",getpid(),getpgid(0));
	sleep(5);
    
	tcsetpgrp(1,getpgid(pid));
	printf("Cur fore GID: %d after change!\n",tcgetpgrp(0));
	wait(NULL);
	return 0;
}
