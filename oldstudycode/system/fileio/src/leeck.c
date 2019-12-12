#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	int fd = open("seek.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
   if(fd < 0)
   {
	   fprintf(stderr,"Open: %s\n",strerror(errno));
	   exit(1);
   }
	char buffer1[]="abcdefghijk\n";
   size_t len= strlen(buffer1);
	if(write(fd,buffer1,len)!=len)
	{
	   fprintf(stderr,"write: %s\n",strerror(errno));
	   exit(1);

	}
	int slen = lseek(fd,2500,SEEK_CUR);
	if(slen < 0)
	{
		fprintf(stderr,"lseek: %s\n",strerror(errno));
		exit(1);
	}
	printf("slen: %d\n",slen);
	char buffer2[]	= "222";
	len = strlen(buffer2);
	if(write(fd,buffer2,len)!=len)
	{
		fprintf(stderr,"write2: %s\n",strerror(errno));
		exit(1);
	}
	close(fd);
	return 0;
}

