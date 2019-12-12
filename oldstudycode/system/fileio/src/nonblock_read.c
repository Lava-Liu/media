#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define BUF_LEN  4096
int set_fl(int fd,int flag)
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
	if(set_fl(STDIN_FILENO,O_NONBLOCK)<0)
	{
		fprintf(stderr,"set_fl: %s\n",strerror(errno));
		exit(1);

	}	
	char buffer[BUF_LEN]= {};
	ssize_t n_read = 0;
	while(1)
	{
	n_read=read(STDIN_FILENO,buffer,BUF_LEN);
	if(n_read > 0)
	{
		if(write(STDOUT_FILENO,buffer,n_read)!=n_read)
		{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);

		}
	}else if(n_read<0)
			{
		fprintf(stderr,"n_read: %s\n",strerror(errno));
		//exit(1);

	}
	else
	{
		printf("stdin finished!\n");
        break;
	}
	sleep(5);
	}

	return 0;
}
