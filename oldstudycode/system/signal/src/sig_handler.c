#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

void print_set(sigset_t set)
{
	int i;
	for(i=31;i>0;i--)
	{
		printf("%d",sigismember(&set,i));
	}
	printf("\n");
}
void sig_handler(int signo)
{
	printf("received signal %d\n",signo);
	if(signo == SIGINT)
	{
		int i;
		for(i=0;i<5;i++)
		{
			sleep(1);
			printf("%d\n",i);
		}

	}
	if(signo == SIGTSTP)
	{
		int i;
		for(i=0;i<5;i++)
		{
			sleep(1);
			printf("%d\n",i);
		}
	}

}

int main(void)
{
	//sigset_t set;
	//sigaddset(&set,SIGINT);
	//sigset_t oldset;
	//sigprocmask(SIG_UNBLOCK,&set,&oldset);
	//print_set(oldset);

	if(signal(SIGINT,sig_handler) == SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	if(signal(SIGTSTP,sig_handler) == SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	/*if(signal(SIGQUIT,sig_handler) == SIG_ERR)
	  {
	  fprintf(stderr,"signal: %s\n",strerror(errno));
	  exit(1);
	  }*/
	while(1)
		pause();
	return 0;
}
