#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>

int main(int argc ,char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"-USAGE %s [HostIP] [HostPort]\n",argv[0]);
		exit(1);
	}
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		fprintf(stderr,"socket: %s\n",strerror(errno));
		exit(1);
	}
	//填写主机地址
	struct sockaddr_in addr;
	//如果不清空，导致后面制0
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2]));

	inet_pton(AF_INET,argv[1],&addr.sin_addr.s_addr);
	
	char *msg = ">>>>>>briup<<<<";
	int len=strlen(msg);
	if(sendto(sockfd,msg,len,0,(struct sockaddr*)&addr,sizeof(addr))<0)
	{
		fprintf(stderr,"sento: %s\n",strerror(errno));
		exit(1);
	}
	printf("Message sent successfuly!\n");
	char buffer[4096] = {0};
	//sockfd 为服务器的套结字
	if(recvfrom(sockfd,buffer,sizeof(buffer),0,NULL,NULL)<0)
	{
		fprintf(stderr,"rcvfrom: %s\n",strerror(errno));
		exit(1);
	}
	printf("buffer:%s\n",buffer);
	close(sockfd);
}

