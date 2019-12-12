#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
void get_lk(int fd)
{
	struct flock flock = {};
	if(fcntl(fd,F_GETLK,&flock)< 0)
	{
		fprintf(stderr,"fcnrl: %s\n",strerror(errno));
		exit(1);

	}
	printf("--------Lock info--------\n");
	switch(flock.l_type)
	{
		case F_RDLCK:
			printf("type: RD\n");
			break;
		case F_WRLCK:
			printf("type: WR\n");
			break;
		case F_UNLCK:
			printf("type: UN\n");
			break;
		default:
			printf("typeL unknow\n");
	}
	printf("whence: %d,start:%ld:len:%ld\n",flock.l_whence,flock.l_start,flock.l_len);
	printf("PID:%d\n",flock.l_pid);

}
int main(void)
{
	int fd = open("fork.ext",O_RDWR|O_CREAT|O_TRUNC,0666);
	if(fd < 0)
	{
		fprintf(stderr,"open: %s\n",strerror(errno));
		exit(1);
	}

	get_lk(fd);
	struct flock flock={};
	flock.l_type=F_WRLCK;
	flock.l_start=0;
	flock.l_whence=SEEK_SET;
	flock.l_len=0;
	flock.l_pid=0;
	if(fcntl(fd,F_SETLK,&flock)<0)
	{
		fprintf(stderr,"fcntl: %s\n",strerror(errno));
		exit(1);

	}
	
	pid_t pid = fork();
	if(pid < 0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else if(pid > 0)
	{
		get_lk(fd);
		printf("i am parent!\n");
	}else
	{
		sleep(10);
		get_lk(fd);
		printf("i am child!\n");

	}
	pause();

	close(fd);
	return 0;
}
