#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
void set_fl(int fd,int flag)
{
	int oldflag = fcntl(fd,F_GETFL);
	if(oldflag < 0)
	{
		fprintf(stderr,"oldflag: %s\n",strerror(errno));
		exit(1);
	}
	int newflag = oldflag | flag;
	if(fcntl(fd,F_SETFL,newflag)<0)
	{
		fprintf(stderr,"fcntl: %s\n",strerror(errno));
		exit(1);
	}
}
void del_fl(int fd,int flag)
{
	int oldflag = fcntl(fd,F_GETFL);
	if(oldflag < 0)
	{
		fprintf(stderr,"oldflag: %s\n",strerror(errno));
		exit(1);
	}
	
	int newflag = oldflag & ~ flag;

	if((fcntl(fd,F_SETFL,newflag))<0)
	{
		fprintf(stderr,"fcntl: %s\n",strerror(errno));
		exit(1);
	}
}
int main(void)
{
	int fd = open("test.txt",O_RDONLY|O_CREAT|O_APPEND|O_NONBLOCK);
		if(fd < 0)
		{
			fprintf(stderr,"open: %s\n",strerror(errno));
			exit(1);
		}
		//set_fl(fd,O_NONBLOCK);
		del_fl(fd,O_NONBLOCK);
		del_fl(fd,O_APPEND);
	int flags =fcntl(fd,F_GETFL); 
		if(flags< 0)
		{
			fprintf(stderr,"flags: %s\n",strerror(errno));
			exit(1);
		}
		if(flags & O_APPEND)
		 printf("O_APPEND\n");
		if(flags & O_NONBLOCK)
		 printf("O_NONBLOCK\n");
		if(flags & O_EXCL)
		 printf("O_EXCL\n");
		if(flags & O_RDWR)
		 printf("O_RDWR\n");
		if(flags & O_WRONLY)
		 printf("O_WRONEY\n");
		if(!(flags & O_RDONLY)&&!(flags & O_RDWR))
		 printf("O_RDONLY\n");
		close(fd);
		return 0;
}
