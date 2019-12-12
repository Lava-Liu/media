#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
typedef struct
{
	long type;
	int  num;
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
	if(msgrcv(msqid,&msg,sizeof(msg.num),1,0)<0)
	{
		fprintf(stderr,"msgrcv: %s\n",strerror(errno));
		exit(1);
	}
	int num1=msg.num;
	printf("recive data : %d\n",msg.num);
	if(msgrcv(msqid,&msg,sizeof(msg.num),1,0)<0)
	{
		fprintf(stderr,"msgrcv: %s\n",strerror(errno));
		exit(1);
	}
	printf("recive data : %d\n",msg.num);
	int num2=msg.num;
	printf("the sum of the num is %d\n",num1+num2);
    msg.num=num1+num2;
	msg.type=2;
	if(msgsnd(msqid,&msg,sizeof(msg.num),0)<0)
	{
		fprintf(stderr,"msgsnd: %s\n",strerror(errno));
		exit(1);
	}
			
	return 0;
}
