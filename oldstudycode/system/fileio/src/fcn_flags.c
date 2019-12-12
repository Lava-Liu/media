#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
void set_fl(int fd,int flag)
{
	flag = flag|O_APPEND;
	flag=fcntl(fd,F_SETFL,flag);
	if(flag < 0)
	{
		printf("flagset: %s\n",strerror(errno));
		exit(1);
	}
}
void del_fl(int fd,int flag)
{
	flag = flag|~O_APPEND;
	flag=fcntl(fd,F_SETFL,flag);
	if(flag < 0)
	{
		printf("flagdel: %s\n",strerror(errno));
		exit(1);
	}
    
}
int main(void)
{
	int fd = open("flag.txt",O_WRONLY|O_CREAT|O_TRUNC|O_NONBLOCK,0666);
	if(fd < 0)
	{
		fprintf(stderr,"open: %s\n",strerror(errno));
		exit(1);
	}
	int flags = 0;
	set_fl(fd,flags);
	del_fl(fd,flags);
	if((flags=fcntl(fd,F_GETFL))<0)
	{
		fprintf(stderr,"funtl: %s\n",strerror(errno));
		exit(1);
	}
	printf("%d\n",flags);
	if(flags & O_CREAT)
		printf("O_CREAT\t");
	if(flags & O_NONBLOCK)
		printf("O_NONBLOCK\t");
	if(flags & O_APPEND)
		printf("O_APPEND\t");
	if(flags & O_TRUNC)
		printf("O_TRUNC\t");
	if(flags & O_RDONLY)
		printf("O_RDONLY\t");
	if(flags & O_WRONLY)
		printf("O_WRONLY\t");
	if(flags & O_RDWR)
		printf("O_RDWR\t");
	close(fd);
	return 0;
}
