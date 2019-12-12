/*
 * Author: liuwei
 * Date: 2013.10.11
 * tcp服务器源文件
 */
#include "tcp_server.h"
#include "dev.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <pthread.h>
//int sockfd;

void *tcp_server(void *arg)
{
	int clientfd=(int )arg;
	send_picture_th(clientfd);
	//send_picture(clientfd);
}
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
	int on=1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

	if(bind(sockfd,(struct sockaddr *)&addr,sizeof(addr))<0)
	{
		fprintf(stderr,"sockfd: %s\n",strerror(errno));
		exit(1);
	}
	if(listen(sockfd,50)<0)
	{
		fprintf(stderr,"listen: %s\n",strerror(errno));
		exit(1);
	}
	int i=0;
	struct sockaddr_in clientaddr;
	while(1)
	{
		
		memset(&clientaddr,0,sizeof(clientaddr));

		int clientlen=sizeof(clientaddr);
		if((clientfd=accept(sockfd,(struct sockaddr *)&addr,&clientlen))<0)
		{
			fprintf(stderr,"sockfd: %s\n",strerror(errno));
			exit(1);
		}
		char addr_buf[16]={0};
		inet_ntop(AF_INET,&addr.sin_addr.s_addr,&addr_buf,16);
		if(i==0)
		{
		    printf("tcp_server is already start!\n");
			ssize_t n_read;
			char buffer[4096]={0};
			if((n_read=read(clientfd,buffer,4096))<0)
			{
				fprintf(stderr,"read: %s\n",strerror(errno));
				exit(1);
			}
			printf("Msg from explore:\n %s\n",buffer);
		}
		pthread_t th[1024];
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
		pthread_create(&th[i],&attr,tcp_server,(void *)clientfd);
		printf("client %d from:%s accept start!\n",i+1,addr_buf);
		i++;
	}



}



