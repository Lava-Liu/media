#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>
int main(void)
{
	struct rlimit rlim={};
	if(getrlimit(RLIMIT_NOFILE,&rlim)<0)
	{
		fprintf(stderr,"getrlimit: %s\n",strerror(errno));
		exit(1);

	}	
	printf("cur:%ld:max:%ld\n",rlim.rlim_cur,rlim.rlim_max);
	pid_t pid;
	pid = fork();
	if(pid < 0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);
	}else if(pid > 0)
	{
		//modify rlimit
		rlim.rlim_cur=4;
		if(setrlimit(RLIMIT_NOFILE,&rlim)<0)
		{
		fprintf(stderr,"setrlimt: %s\n",strerror(errno));
		exit(1);

		}
		printf("set rlimt success!\n");
	}else
	{
		sleep(5);
		int fd1,fd2;
		fd1=open("1.txt",O_CREAT|O_RDWR,0666);
		if(fd1 < 0)
		{
		fprintf(stderr,"open: %s\n",strerror(errno));
		exit(1);
		}
		printf("%d\n",fd1);
		fd2=open("2.txt",O_CREAT|O_RDWR,0666);
		if(fd2 < 0)
		{
		fprintf(stderr,"open2: %s\n",strerror(errno));
		exit(1);
		}
		printf("%d\n",fd2);
		close(fd1);
		close(fd2);
	}
	pause();
	return 0;
}
