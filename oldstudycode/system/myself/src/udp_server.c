#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>
char *get_addr(struct sockaddr_in *addr)
{
	static char ip_port[256];
	char ip[16] = {0};
	inet_ntop(AF_INET,&addr->sin_addr.s_addr,ip,16);
	unsigned short int port = ntohs(addr->sin_port);
	sprintf(ip_port,"%s:%d",ip,port);
	return ip_port;
}
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage %s [hostport] \n",strerror(errno));
		exit(1);
	}
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		fprintf(stderr,"sockfd : %s\n",strerror(errno));
		exit(1);
	}

	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
	addr.sin_port=htons(atoi(argv[1]));
	addr.sin_addr.s_addr=INADDR_ANY;

	if(bind(sockfd,(struct sockaddr *)&addr,sizeof(addr))<0)
	{
		fprintf(stderr,"bind: %s\n",strerror(errno));
		exit(1);
	}

	struct sockaddr_in clientaddr;
	memset(&clientaddr,0,sizeof(clientaddr));
	char buffer[4096]={0};
	int len=sizeof(clientaddr);
	if(recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&clientaddr,&len)<0)
	{
		fprintf(stderr,"sockfd: %s\n",strerror(errno));
		exit(1);
	}
	printf("buffer: %s\n",buffer);
	printf("%s:%s\n",get_addr(&clientaddr),buffer);
	time_t curTime;
	curTime = time(NULL);
	memset(buffer,0,sizeof(buffer));
	strcpy(buffer,ctime(&curTime));

	if(sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)&clientaddr,sizeof(clientaddr))<0)
	{
		fprintf(stderr,"sendto: %s\n",strerror(errno));
		exit(1);

	}
	printf("Message sent successfuly!\n");
	close(sockfd);
	return 0;
}
