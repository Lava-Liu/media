#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#define SIZE 100
int const size=100;

int main(void)
{
	//内存映射文件打开方式
	int fd = open("seek.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
	if(fd < 0)
	{
		fprintf(stderr,"open: %s \n",strerror(errno));
		exit(1);
	}
	lseek(fd,SIZE-1,SEEK_END);
	char buffer='\0';
	if(write(fd,&buffer,1)!=1)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);
	}

    
	char *ptr = NULL;
	ptr = (char * )mmap(NULL,SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(ptr == MAP_FAILED)
	{
		fprintf(stderr,"Mmap: %s \n",strerror(errno));
		exit(1);
	}
	memset(ptr,'a',SIZE);
	char *str = "this is input by mmaped!\n";
	int len = strlen(str);
	memcpy(ptr,str,len);
	*ptr = 'Z';
	*(ptr+3)='a';
	if(munmap(ptr,SIZE)<0)
	
	{
		fprintf(stderr,"open: %s \n",strerror(errno));
		exit(1);
	}

	return 0;
}
