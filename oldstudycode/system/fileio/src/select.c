#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_LEN 4096
int main(void)
{
	fd_set rset;
	FD_ZERO(&rset);
	FD_SET(STDIN_FILENO,&rset);
	struct timeval tval;
	memset(&tval,0,sizeof(tval));
	tval.tv_sec = 5;
	tval.tv_usec = 0;
	int ret;
	while((ret = select(STDIN_FILENO+1,&rset,NULL,NULL,&tval))!=-1)
	{
		if(ret > 0)
		{
			if(FD_ISSET(STDIN_FILENO,&rset))
			{
				char buffer[BUF_LEN]= {};
				ssize_t n_read = 0;
				n_read=read(STDIN_FILENO,buffer,BUF_LEN);
				printf("--fd is ready!--\n");
				write(STDOUT_FILENO,buffer,n_read);
			}
		}
		else
		{
			printf("timeout!\n");
		}
		FD_ZERO(&rset);
		FD_SET(STDIN_FILENO,&rset);

		tval.tv_sec =5;
		tval.tv_usec =0;
	}
	return 0;
}
