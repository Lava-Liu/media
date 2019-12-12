#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"Usage truncate [filename] [length]\n");
		exit(1);
	}
	if(truncate(argv[1],atoi(argv[2]))<0)
	{
		fprintf(stderr,"truncate: %s\n",strerror(errno));
		exit(1);
	}
	return 0;
}
