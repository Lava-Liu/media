#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#define BUF_LEN 4096
int main(int argc ,char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"Usage %s [hostip] [hostport]\n",argv[0]);
		exit(1);
	}
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(atoi(argv[2]));
	inet_pton(AF_INET,argv[1],&addr.sin_addr.s_addr);
	printf("me:\n");
	char buffer[4096]={0};
	gets(buffer);
	int len=strlen(buffer);
	if(sendto(sockfd,buffer,len,0,(struct sockaddr *)&addr,sizeof(addr))<0)
	{
		fprintf(stderr,"sendto: %s\n",strerror(errno));
		exit(1);
	}
	printf("sent message successfuly!\n");
	memset(&buffer,0,sizeof(buffer));
	if(recvfrom(sockfd,buffer,sizeof(buffer),0,NULL,NULL)<0)
	{
		fprintf(stderr,"recv: %s\n",strerror(errno));
		exit(1);
	}
	printf("buffer:%s\n",buffer);

	return 0;
}
