#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
int main(int argc,char *argv[])
{

	if(argc < 2)
	{
		fprintf(stderr,"Usage mkdir [dirname]");
		exit(1);
	}
	if(mkdir(argv[1],0775)<0)
	{
		fprintf(stderr,"mkdir: %s\n",strerror(errno));
		exit(1);
	}
	return 0;
}
