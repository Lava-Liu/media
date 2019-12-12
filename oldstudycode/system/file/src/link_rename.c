#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc,char * argv[])
{

	if(argc < 3)
	{
		fprintf(stderr,"usr %s [filename ] [filename ]\n",argv[0]);
		exit(1);
	}

	if(link(argv[1],argv[2])<0)
	{
		fprintf(stderr,"link: %s\n",strerror(errno));
		exit(1);

	}
	if(rename(argv[2],"/home/silence/test.hln")<0)
	{
		fprintf(stderr,"rename: %s\n",strerror(errno));
		exit(1);
	}

	return 0;
}
