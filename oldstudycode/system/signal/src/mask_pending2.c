#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
void print(sigset_t set)
{
	int i;
	for(i=31;i>0;i--)
	{
		printf("%d",sigismember(&set,i));
	}
	printf("\n");
}
void print_cur()
{
	sigset_t cur;
	sigprocmask(0,NULL,&cur);
	printf("cur:");
	print(cur);
}
void printf_pen()
{
	sigset_t pen;
	sigpending(&pen);
	printf("pending: ");
	print(pen);
}
void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		print_cur();
		sleep(5);
		printf_pen();
	}
}
int main(void)
{
	if(signal(SIGINT,sig_handler)==SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	sigset_t set,oldset;
	sigfillset(&set);
	print(set);
	if(sigprocmask(SIG_SETMASK,&set,&oldset)<0)
	{
		fprintf(stderr,"si_mask: %s\n",strerror(errno));
		exit(1);
	}
	print_cur();
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigaddset(&set,SIGTSTP);
	sigprocmask(SIG_UNBLOCK,&set,NULL);
	print_cur();



	
	while(1)
	pause();
}
