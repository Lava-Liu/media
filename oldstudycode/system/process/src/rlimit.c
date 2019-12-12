#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/resource.h>
int main(void)
{
    struct rlimit rlim = {};
	if(getrlimit(RLIMIT_NOFILE,&rlim)!=0)
	{
		fprintf(stderr,"getrlimir: %s\n",strerror(errno));
		exit(1);
	}
	printf("cur limit:%ld\n",rlim.rlim_cur);
	printf("max limit:%ld\n",rlim.rlim_max);
	rlim.rlim_cur=1024;
	rlim.rlim_max=5000;
	if(setrlimit(RLIMIT_NOFILE,&rlim)!=0)
	{
		fprintf(stderr,"getrlimir: %s\n",strerror(errno));
		exit(1);
	}
	printf("cur limit:%ld\n",rlim.rlim_cur);
	printf("max limit:%ld\n",rlim.rlim_max);
	int fd1;
	int fd2;
	if((fd1=dup(STDOUT_FILENO))<0)
	{
		fprintf(stderr,"dup: %s\n",strerror(errno));
		exit(1);

	}
	if((fd2=dup(STDOUT_FILENO))<0)
	{
		fprintf(stderr,"dup2: %s\n",strerror(errno));
		exit(1);
	}
	close(fd1);
	close(fd2);


	return 0;
}
