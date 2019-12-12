#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <utime.h>

int main(int argc,char * argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"%s\n",argv[0]);
		exit(1);
	}
	struct utimbuf utm ={0,0};
	if(utime(argv[1],&utm)<0)
	{
		fprintf(stderr,"utime: %s\n",strerror(errno));
		exit(1);

	}
	return 0;
}
