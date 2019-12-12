#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	int i;
	if((pid=fork())<0)
	{
		fprintf(stderr,"fork : %s\n",strerror(errno));
		exit(1);
	}else if(pid == 0)
	{
		if((pid=fork())<0)
		{
			fprintf(stderr,"fork : %s\n",strerror(errno));
			exit(1);
		}else if(pid == 0)
		{
			printf("I am 3");
			sleep(100);

		}else
		{
			printf("I am 2 ,I am going to die!");
			exit(0);
		}
	}else
	{
		wait(NULL);
		printf("first child is kill!");
		sleep(100);

	}

	return 0;
}
