#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <time.h>
char *get_addr(struct sockaddr_in *addr)
{
	static char ip_port[256];
	char ip[16]={0};
	int port=ntohs(addr->sin_port);
	inet_ntop(AF_INET,&addr->sin_addr.s_addr,ip,16);
	sprintf(ip_port,"%s:%d",ip,port);
	return ip_port;
}
int main(int argc,char *argv[])
{
	if(argc <2)
	{
		
		fprintf(stderr,"usage %s [hostport]\n",argv[0]);
		exit(1);
	}
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
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
	char buffer[4096]={0};
	int len=sizeof(addr);

	if(recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,&len)<0)
	{
		fprintf(stderr,"recv: %s\n",strerror(errno));
		exit(1);

	}
	printf("IP:%s buffer: %s\n",get_addr(&addr),buffer);
	time_t curtime=time(NULL);
	memset(buffer,0,sizeof(buffer));
	strcpy(buffer,ctime(&curtime));
	len=strlen(buffer);
	if(sendto(sockfd,buffer,len,0,(struct sockaddr *)&addr,sizeof(addr))<0)
	{
		fprintf(stderr,"recv: %s\n",strerror(errno));
		exit(1);

	}
	printf("send message successfuly!\n");
			
	return 0;
}
