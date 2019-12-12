#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
int main(int argc ,char * argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"usage %s [filename]\n",argv[0]);
		exit(1);
	}
	if(access(argv[1],W_OK) <  0)
	{
		fprintf(stderr,"access %s\n",strerror(errno));
		exit(1);

	}
	printf("access success!\n");
	return 0;
}
