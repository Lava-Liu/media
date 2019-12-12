#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/msg.h>
typedef struct
{
	long mtype;
	int start;
	int end;
}Msg;
int main(int argc , char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"usage: %s key\n",argv[0]);
		exit(1);
	}
	key_t key=ftok(argv[1],0);
	Msg m1 = {1,100,100};
	Msg m2 = {2,200,200};
	Msg m3 = {4,400,400};
	int msq_id;
	if(msq_id=msgget(key,IPC_CREAT|IPC_EXCL|0777)<0)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);
	}else
	{
		printf("msq id: %d\n",msq_id);
	}
	if((msgsnd(msq_id,&m1,sizeof(m1),IPC_NOWAIT)<0)||
	   (msgsnd(msq_id,&m2,sizeof(m2),IPC_NOWAIT)<0)||
	   (msgsnd(msq_id,&m3,sizeof(m3),IPC_NOWAIT)<0))
	{
		fprintf(stderr,"%s\n",strerror(errno));
	}
	struct msqid_ds buffer;
	if(msgctl(msq_id,IPC_STAT,&buffer)<0)
	{
		fprintf(stderr,"%s\n",strerror(errno));

	}else
	{
		printf("#msg: %ld\n",buffer.msg_qnum);
	}

	return 0;
}
