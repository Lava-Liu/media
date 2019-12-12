#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
//打印信号集的内容
void print_sigset(sigset_t set)
{
	int i;
	for(i=31;i>0;i--)
	
	{
		printf("%d",sigismember(&set,i));
	}
	printf("\n");
}
void print_cursigset()
{
	sigset_t cur_sigset;
	sigemptyset(&cur_sigset);
	sigprocmask(0,NULL,&cur_sigset);
	printf("cur:");
	print_sigset(cur_sigset);
}
int main(void)
{
	sigset_t new_sigset,old_sigset;
	sigfillset(&new_sigset);
	print_sigset(new_sigset);
	if(sigprocmask(SIG_SETMASK,&new_sigset,&old_sigset)<0)
	{
		fprintf(stderr,"sigpromask: %s\n",strerror(errno));
		exit(1);
	}
	print_sigset(old_sigset);
	print_cursigset();
	sigemptyset(&new_sigset);
	sigaddset(&new_sigset,SIGINT);
	sigprocmask(SIG_UNBLOCK,&new_sigset,NULL);
	print_cursigset();
	sleep(5);
	sigset_t pendingset;
	sigpending(&pendingset);
	print_sigset(pendingset);
	while(1)
		pause();
	return 0;
}
