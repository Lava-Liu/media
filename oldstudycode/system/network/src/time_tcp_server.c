#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <netdb.h>
#include <unistd.h>
#include <memory.h>
#include <time.h>

int sockfd;
void out_addr(struct sockaddr_in *client)
{
	int port = ntohs(client->sin_port);
	char ip[16];
	memset(ip,0,sizeof(ip));
	inet_ntop(AF_INET,&client->sin_addr.s_addr,ip,sizeof(ip));
	printf("%s(%5d) connectd!\n",ip,port);
}
void do_service(int fd)
{
	long t = time(0);
	char *s = ctime(&t);
	size_t size = strlen(s)*sizeof(char);
	if(write(fd,s,size)!=size)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
	}
}
void sig_handler(int signo)
{
	if(SIGINT == signo)
	{
		printf("server will  be closed\n");
		close(sockfd);
		exit(0);
	}
}

int main(int argc ,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"usage %s\n",argv[0]);
		exit(1);
	}
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(atoi(argv[1]));
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	memset(serveraddr.sin_zero,0,8);

	if(bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0)
	{
		fprintf(stderr,"bind: %s\n",strerror(errno));
		exit(1);
	}
	if(listen(sockfd,10)<0)
	{
		fprintf(stderr,"listen : %s\n",strerror(errno));
		exit(1);
	}
	struct sockaddr_in clientaddr;
	socklen_t len = sizeof(clientaddr);
	while(1)
	{
		int fd= accept(sockfd,(struct sockaddr *)&clientaddr,&len);
		if(fd < 0)
		{
		fprintf(stderr,"accept : %s\n",strerror(errno));
		exit(1);
		continue;

		}
		out_addr(&clientaddr);
		do_service(fd);
		close(fd);
	}



	return 0;
}
