#include "tell.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

static int fd[2];
void init()
{
	if(pipe(fd)<0)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);
	}
}

void wait_pipe()
{
	char c;
	if(read(fd[0],&c,1)<0)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);

	}
}
void notify_pipe()
{
	char c = 'c';
	if(write(fd[1],&c,1)!=1)
	{

		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);
	}
}
void destroy_pipe()
{
	close(fd[0]);
	close(fd[1]);
}

