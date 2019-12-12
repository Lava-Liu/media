#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc ,char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"use %s [filename] [filename ]",argv[0]);
		exit(1);
	}
	if(symlink(argv[1],argv[2])<0)
	{
		fprintf(stderr,"symlink %s\n",strerror(errno));
		exit(1);

	}
	char buffer[4096]={};
	ssize_t n_read;
	if((n_read=readlink(argv[2],buffer,4096))<0)
	{
		fprintf(stderr,"readlink: %s\n",strerror(errno));
		exit(1);

	}
	buffer[n_read]='\n';
	write(STDOUT_FILENO,buffer,n_read+1);

	return 0;
}
