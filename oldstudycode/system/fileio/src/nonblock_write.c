#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define BUF_LEN 50000
int set_fl(int fd,unsigned int flag)
{
	int oldflag = fcntl(fd,F_GETFL);
	if(oldflag < 0)
	{
		fprintf(stderr,"oldflag: %s\n",strerror(errno));
		exit(1);
	}
	int newflag = oldflag | flag;
	return fcntl(fd,F_SETFL,newflag);
}
int main(void)
{   
    if(set_fl(STDOUT_FILENO,O_NONBLOCK)<0)
	{
		fprintf(stderr,"set_fl: %s\n",strerror(errno));
		exit(1);

	}
	char buffer[BUF_LEN]={};
	ssize_t total =0,cur = 0;
	total = read(STDIN_FILENO,buffer,BUF_LEN);
	if(total < 0)
	{
		fprintf(stderr,"read: %s\n",strerror(errno));
		exit(1);

	}
	while(total > cur)
	{
		ssize_t size = write(STDOUT_FILENO,buffer+cur,total-cur);
		if(size < 0)
		{
		      fprintf(stderr,"write: %s\n",strerror(errno));
		}
		else
		{
			cur +=size;
		    fprintf(stderr,"write: %d->%d\n",size,cur);
		}
	}
	return 0;
}
