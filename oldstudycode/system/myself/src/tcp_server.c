#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <time.h>
#include <pthread.h>
#define BUF_SIZE 4096
void *do_service(void *arg)
{
	int clientfd=(int)arg;
	struct sockaddr_in addr;
	int len = sizeof(addr);
	memset(&addr,0,len);
	if(getpeername(clientfd,(struct sockaddr *)&addr,&len)<0)
	{
		fprintf(stderr,"getpeer: %s\n",strerror(errno));
		pthread_exit((void *)-1);
	}
	char ip[16]={0};
	inet_ntop(AF_INET,&addr.sin_addr.s_addr,ip,16);
	printf("%s connected to server!",ip);
	while(1)
	{
		char buffer[BUF_SIZE]={0};
		ssize_t nread=read(clientfd,buffer,BUF_SIZE);
		if(nread < 0)
		{
			fprintf(stderr,"read : %s\n",strerror(errno));
			pthread_exit((void *)-1);
		}
		else if(nread == 0)
		{
			printf("%s close  Connection!\n",ip);
			pthread_exit((void *)-1);
		}
		else
		{
			printf("%s: \n",ip);
			printf("\t%s\n",buffer);
			//
			time_t curTime = time(NULL);
			char time_buf[256]={0};
			strcpy(time_buf,ctime(&curTime));
			int len = strlen(time_buf);
			time_buf[len-1] = '\0';
			if(write(clientfd,time_buf,len) != len)
			{
				fprintf(stderr,"write: %s\n",strerror(errno));
				pthread_exit((void *)-1);

			}
		}
	}

}
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"usage %s [hostport]",argv[0]);
		exit(1);
	}
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		fprintf(stderr,"sockfd: %s\n",strerror(errno));
		exit(1);
	}
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(atoi(argv[1]));
	addr.sin_addr.s_addr=INADDR_ANY;

	if(bind(sockfd,(struct sockaddr *)&addr,sizeof(addr))<0)
	{
		fprintf(stderr,"bind: %s\n",strerror(errno));
		exit(1);
	}
	if(listen(sockfd,50)<0)
	{
		fprintf(stderr,"listen: %s\n",strerror(errno));
		exit(1);
	}
	struct sockaddr_in clientaddr;
	while(1)
	{
		int clientfd = accept(sockfd,NULL,NULL);
		pthread_t th;
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
		pthread_create(&th,&attr,do_service,(void *)clientfd);
	}




	return 0;
}
