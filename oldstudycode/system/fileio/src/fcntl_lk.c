#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define SET_RDLK(fd) lock_reg(fd,F_RDLCK,F_SETLK,0,SEEK_SET,0)
#define SET_WRLK(fd) lock_reg(fd,F_WRLCK,F_SETLK,0,SEEK_SET,0)
#define SET_RDLKW(fd) lock_reg(fd,F_RDLCK,F_SETLKW,0,SEEK_SET,0)
#define SET_WRLKW(fd) lock_reg(fd,F_WRLCK,F_SETLKW,0,SEEK_SET,0)
#define UN_LK(fd) lock_reg(fd,F_UNLCK,F_SETLKW,0,SEEK_SET,0)
int lock_reg(int fd,int type,int cmd,off_t start,int whence,off_t len)
{
	struct flock lock;
	lock.l_type = type;
	lock.l_start = start;
	lock.l_whence = whence;
	lock.l_len = len;
	return (fcntl(fd,cmd,&lock));

}
int main(int argc,char*argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"usage %s [contnet] [file]\n",argv[0]);
		exit(1);
	}
	int fd = open(argv[2],O_WRONLY|O_CREAT,0666);
	if(fd < 0)
	{
		fprintf(stderr,"open: %s\n",strerror(errno));
		exit(1);
	}
	
	int len = strlen(argv[1]);
	int size = 0;
	if(SET_WRLKW(fd)<0)
	//if(lock_reg(fd,F_WRLCK,F_SETLKW,0,SEEK_SET,0)<0)
	{

		fprintf(stderr,"lock_reg %s\n",strerror(errno));
		exit(1);
	}
	else
	{
		printf("lock success!\n");
	}
	lseek(fd,0,SEEK_END);
	while(len > size)
	{
		int n_write;

		if((n_write=write(fd,argv[1]+size,1))!=1)
		{
			fprintf(stderr,"write %s\n",strerror(errno));
			exit(1);
		}
		size +=n_write;
		sleep(1);
		printf(" one byte written by %d\n",getpid());



	}
	if(lock_reg(fd,F_UNLCK,F_SETLKW,0,SEEK_SET,0)<0)
	{

		fprintf(stderr,"lock_reg %s\n",strerror(errno));
		exit(1);
	}else
	{
		printf("unlock success!\n");
	}

	return 0;
}
