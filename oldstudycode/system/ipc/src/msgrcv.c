#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
typedef struct
{
	long type;
	char str[256];
}Msg;
int main(void)
{
	int msqid=msgget(1,0);
	if(msqid <0)
	{
		fprintf(stderr,"msgget: %s\n",strerror(errno));
		exit(1);
	}
	//char buffer[256];
	Msg msg;
	if(msgrcv(msqid,&msg,sizeof(msg.str),1,0)<0)
	{
		fprintf(stderr,"msgrcv: %s\n",strerror(errno));
		exit(1);
	}
	printf("recive data : %s\n",msg.str);
	return 0;
}
