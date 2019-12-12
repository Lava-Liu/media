#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
typedef struct
{
	long mtype;
	int start;
	int end;
}Msg;
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"usage %s \nkey",argv[0]);
		exit(1);
	}
	key_t key =ftok(argv[1],0);
	long type = atoi(argv[2]);
	int msq_id;
	if((msq_id = msgget(key,0777))<0)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);
	}else
	{
		printf("queue id: %d\n",msq_id);
	}
	Msg buffer;
	if(msgrcv(msq_id,&buffer,sizeof(buffer),type,IPC_NOWAIT)<0)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);

	}else
	{
		printf("%ld,%d,%d\n",buffer.mtype,buffer.start,buffer.end);
	}
	return 0;
}
