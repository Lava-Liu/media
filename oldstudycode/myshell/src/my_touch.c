#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage touch [filename]\n");
		exit(1);
	}
	int i;
	for(i=argc-1;i>0;i--)
	{
	if(creat(argv[i],0666)<0)
	{
		fprintf(stderr,"creat: %s\n",strerror(errno));
		exit(1);
	}
	}
	return 0;
}

