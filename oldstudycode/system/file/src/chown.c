#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
int main(void)
{
	if(chown("chown.txt",0,0)<0)
	{
		fprintf(stderr,"chown: %s\n",strerror(errno));
		exit(1);
	}
	return 0;
}
