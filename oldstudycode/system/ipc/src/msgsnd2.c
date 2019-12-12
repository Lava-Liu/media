#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
typedef struct 
{
	long type;
	int  num;
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
	msg.num=1;
	if(msgsnd(msqid,&msg,sizeof(msg.num),0)<0)
	{
		fprintf(stderr,"msgsnd: %s\n",strerror(errno));
		exit(1);
	}
	printf("Message queue 1 send successfuly!\n");
	msg.num=9;
	if(msgsnd(msqid,&msg,sizeof(msg.num),0)<0)
	{
		fprintf(stderr,"msgsnd: %s\n",strerror(errno));
		exit(1);
	}
	printf("Message queue 2 send successfuly!\n");
	
	if(msgrcv(msqid,&msg,sizeof(msg.num),2,0)<0)
	{
		fprintf(stderr,"msgrcv: %s\n",strerror(errno));
		exit(1);
	}
	printf("recive data : %d\n",msg.num);
	
	

	return 0;
}
