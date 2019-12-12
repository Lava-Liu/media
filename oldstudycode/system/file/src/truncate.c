#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc ,char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"usage %s [filename] [filename]\n",argv[0]);
		exit(1);
	}
	if(truncate(argv[1],atoi(argv[2]))<0)
	{
		fprintf(stderr,"truncate %s\n",strerror(errno));
		exit(1);

	}
	return 0;
}
