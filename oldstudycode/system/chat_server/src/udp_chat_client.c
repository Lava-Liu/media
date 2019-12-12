#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <netdb.h>
#define BUF_SIZE 4096
char buffers[BUF_SIZE];
void *do_server(void *arg)
{
	int fd=(int)arg;
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	int len=sizeof(addr);
	if(getpeername(fd,(struct sockaddr *)&addr,&len)<0)
	{
		fprintf(stderr,"get_name:%s\n",strerror(errno));
		exit(1);
	}
	char ip[16]={0};
	inet_ntop(AF_INET,&addr,sizeof(addr));
	char buffer[BUF_SIZE]={0};
	while(1)
	{
	if(read(fd,buffer,BUF_SIZE)<0)
	{
		fprintf(stderr,"read: %s\n",strerror(errno));
		exit(1);
	}
	printf("%s:%s\n",ip,buffer);
	}
}
void *do_server2(void *arg)
{
	int fd=(int)arg;
	while(1)
	{
		
		gets(buffers);
		int len=strlen(buffers);
		if(write(fd,buffers,len)!=len)
		{
			fprintf(stderr,"write: %s\n",strerror(errno));
			exit(1);
		}

	}
}
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"usage%s [hostport]\n",argv[0]);
		exit(1);
	}
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		fprintf(stderr,"sock: %s\n",strerror(errno));
		exit(1);
	}
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(atoi(argv[1]));
    addr.sin_addr.s_addr=INADDR_ANY;
	if(bind(sockfd,(struct sockaddr *)&addr,sizeof(addr))<0)
	{
		fprintf(stderr,"sockfd: %s\n",strerror(errno));
		exit(1);
	}
	while(1)
	{
	   if(listen(sockfd,0)<0)
	   {
		   fprintf(stderr,"sockfd: %s\n",strerror(errno));
		   exit(1);
	   }
	   int clientfd;
	   if((clientfd=accept(sockfd,NULL,NULL))<0)
	   {
		   fprintf(stderr,"accept: %s\n",strerror(errno));
		   exit(1);
	   }
	   pthread_t th;
	   pthread_t th2;
	   pthread_attr_t attr;
	   pthread_attr_init(&attr);
	   pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	   if(pthread_create(&th,&attr,do_server,(void *)clientfd)!=0)
	   {
		   fprintf(stderr,"th_create: %s\n",strerror(errno));
		   exit(1);
	   }
	   if(pthread_create(&th2,&attr,do_server2,(void *)clientfd)!=0)
	   {
		   fprintf(stderr,"th_create: %s\n",strerror(errno));
		   exit(1);
	   }

	}
	return 0;
}
