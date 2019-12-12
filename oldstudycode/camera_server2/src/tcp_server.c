#include "tcp_server.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
//int sockfd;

//初始化服务器
void init()
{
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		fprintf(stderr,"socket: %s\n",strerror(errno));
		exit(1);
	}
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(10000);
	addr.sin_addr.s_addr=INADDR_ANY;

	//设置端口可重用
	//int on=1;
	//setsockopt(sockfd,SQL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

	if(bind(sockfd,(struct sockaddr *)&addr,sizeof(addr))<0)
	{
		fprintf(stderr,"sockfd: %s\n",strerror(errno));
		exit(1);
	}
	if(listen(sockfd,0)<0)
	{
		fprintf(stderr,"listen: %s\n",strerror(errno));
		exit(1);
	}
	
	if((clientfd=accept(sockfd,NULL,NULL))<0)
	{
		fprintf(stderr,"sockfd: %s\n",strerror(errno));
		exit(1);
	}
	printf("tcp_server is already start!\n");
	ssize_t n_read;
	char buffer[4096]={0};
	if((n_read=read(clientfd,buffer,4096))<0)
	{
		fprintf(stderr,"read: %s\n",strerror(errno));
		exit(1);
	}
	printf("Msg from explore: %s\n",buffer);

	

}



