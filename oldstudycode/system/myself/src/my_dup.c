#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#define  SIZE 1024
int my_dup(int fd,int fd2)
{
	if(fd2 < 3)
	{
		int dup_1;
		close(fd2);
		while(1)
		{
			if((dup_1=dup(fd))<0)
			{
				fprintf(stderr,"dup_1: %s\n",strerror(errno));
				exit(1);
			}
			if(dup_1==fd2)
			{
				break;
			}else
			{
				close(dup_1);
			}
		}
	}else
	{
		int dup_2;
		int array[SIZE];
		int i=0;
		int j;
		while(1)
		{
			if((dup_2=dup(fd))<0)
			{
				fprintf(stderr,"dup_1: %s\n",strerror(errno));
				exit(1);
			}
			array[i++]=dup_2;
			if(dup_2 == fd2 )
			{
				for(j=0;j<i-1;j++)
				{
					close(array[j]);
				}
				break;
			}
			else if(dup_2 > fd2)
			{
				close(fd2);
			}
		}
	}
	return fd2;
}
int main(void)
{
	int fd4 = open("my_dup.txt",O_RDWR);
	if(fd4 < 0)
	{
		fprintf(stderr,"fd4: %s\n",strerror(errno));
		exit(1);
	}
	int dup3=my_dup(fd4,6);
	int dup5=my_dup(6,STDERR_FILENO);
	fprintf(stderr,"this is a useful  function!%s\n",strerror(errno));
	return 0;
}
