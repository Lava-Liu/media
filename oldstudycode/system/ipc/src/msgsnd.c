#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
typedef struct 
{
	long type;
	char str[256];
}Msg;

int main(void )
{//创建消息队列
	int msqid=msgget(1,IPC_CREAT|IPC_EXCL|0666);
	if(msqid < 0)
	{
		fprintf(stderr,"msgget: %s\n",strerror(errno));
		//exit(1);
	}


	//msgctl(msqid,IPC_RMID,0);
	//数据发送
	Msg msg;
	msg.type=1;
	strcpy(msg.str,"Message");
	if(msgsnd(msqid,&msg,sizeof(msg.str),0)<0)
	{
		fprintf(stderr,"msgsnd: %s\n",strerror(errno));
		exit(1);
	}
	printf("Message queue send successfuly!\n");
	
	

	return 0;
}
