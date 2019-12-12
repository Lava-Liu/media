#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <netdb.h>

int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"usage %s [hostip] [hostport]\n",argv[0]);
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
	addr.sin_port=htons(atoi(argv[2]));
	inet_pton(AF_INET,argv[1],&addr.sin_addr.s_addr);
	if(connect(sockfd,(struct sockaddr *)&addr,sizeof(addr))<0)
	{
		fprintf(stderr,"sockfd: %s\n",strerror(errno));
		exit(1);
	}
	printf("system is connect !\n");
	while(1)
	{
		char buffer[4096]={0};
		gets(buffer);
		int len=strlen(buffer);
		if(write(sockfd,buffer,len)!=len)
		{
			fprintf(stderr,"write: %s\n",strerror(errno));
			exit(1);
		}
		printf("msgsend successfuly!\n");
	}
	close(sockfd);
	return 0;
}
