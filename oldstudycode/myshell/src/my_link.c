#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int argc,char*argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"Usage [filename] [linkfilename]\n");
		exit(1);
	}
	if(argc == 4)
	{
		if(strcmp(argv[1],"-s"))
		{
			printf("unknow comad\n");
			exit(1);
		}
		else if(symlink(argv[2],argv[3])<0)
		{
			fprintf(stderr,"symlink: %s\n",strerror(errno));
			exit(1);
		}
		return 0;

	}
	if(link(argv[1],argv[2])<0)
	{
		fprintf(stderr,"link: %s\n",strerror(errno));
		exit(1);
	}
	return 0;
}

