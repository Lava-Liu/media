#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
int main(void)
{
	int fd=open("pipe.fifo",O_WRONLY);
	
	if(fd<0)
	{
		fprintf(stderr,"open: %s\n",strerror(errno));
		exit(1);
	}
	char buffer[256]={0};
	strcpy(buffer,"Message");
	int len=strlen(buffer);
	if(write(fd,buffer,len)!=len)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);
	}
	printf("write finished!\n");
	return 0;
}
