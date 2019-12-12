#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#define BUF_SIZE 4096
void do_service(int sockfd)
{
	printf("Me:\n\t");
	char buffer[BUF_SIZE] = {};
	gets(buffer);
	int len = strlen(buffer);
	if(write(sockfd,buffer,len)!= len)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);
	}
	char time_buf[256]={0};
	ssize_t nread= read(sockfd,time_buf,sizeof(time_buf));
	if(nread < 0)
	{
		fprintf(stderr,"read: %s\n",strerror(errno));
		exit(1);

	}else if(nread =0)
	{
		fprintf(stderr,"Sever connection is closed!\n");
		return;
	}else
	{
	    printf("( %s )\n",time_buf);
	}
}
int main(int argc ,char *argv[])
{

	if(argc < 3)
	{
		fprintf(stderr,"%s [hostip] [host port]\n",argv[0]);
		exit(1);
	}
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		fprintf(stderr,"sockfd: %s\n",strerror(errno));
		exit(1);
	}
    struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(atoi(argv[2]));
	inet_pton(AF_INET,argv[1],&addr.sin_addr.s_addr);

	if(connect(sockfd,(struct sockaddr *)&addr,sizeof(addr))<0)
	{
		fprintf(stderr,"connect: %s\n",strerror(errno));
		exit(1);
	}
	printf("Connect to server successfuly!\n");
	
	while(1)
	{
		do_service(sockfd);
	}

	return 0;
}
