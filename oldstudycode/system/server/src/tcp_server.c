#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
int main(int argc ,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"usage %s [hostport]\n",argv[0]);
		exit(1);
	}
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		fprintf(stderr,"sockfd:%s\n",strerror(errno));
		exit(1);
	}
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(atoi(argv[1]));
	addr.sin_addr.s_addr=INADDR_ANY;
	if(bind(sockfd,(struct sockaddr *)&addr,sizeof(addr))<0)
	{
		fprintf(stderr,"sockfd: %s\n",strerror(errno));
		exit(1);
	}
	if(listen(sockfd,0)<0)
	{
		fprintf(stderr,"sockfd:  %s\n",strerror(errno));
		exit(1);
	}
	int clientfd;
	if((clientfd=accept(sockfd,NULL,NULL))<0)
	{
		fprintf(stderr,"sockfd:  %s\n",strerror(errno));
		exit(1);
	}
	while(1)
	{
	ssize_t nread;
	char buffer[4096]={0};
	if((nread=read(clientfd,buffer,4096))<0)
	{
		fprintf(stderr,"read: %s\n",strerror(errno));
		exit(1);
	}
	printf("buffer: %s\n",buffer);
	}
	close(sockfd);

	return 0;
}
