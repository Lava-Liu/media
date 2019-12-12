#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage rmdir [dirname]\n");
		exit(1);
	}
	if(rmdir(argv[1])<0)
	{
		fprintf(stderr,"rmdir: %s\n",strerror(errno));
		exit(1);
	}
	return 0;
}
