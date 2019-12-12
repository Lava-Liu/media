#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"%s [file name ]\n",argv[1]);
		exit(1);
	}
	int ret;
	//ret = unlink(argv[1]);
	//ret = remove(argv[1]);
	ret = rmdir(argv[1]);
	if(ret < 0)
	{
		fprintf(stderr,"unlink : %s \n",strerror(errno));
		exit(1);

	}
	return 0;
}
