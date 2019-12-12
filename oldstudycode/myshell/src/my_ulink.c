#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int argc,char*argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage [linkfilename]\n");
		exit(1);
	}
	if(unlink(argv[1])<0)
	{
		fprintf(stderr,"unlink: %s\n",strerror(errno));
		exit(1);
	}
	return 0;
}

