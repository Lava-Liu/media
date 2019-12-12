#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
print_set(sigset_t oldset)
{
	int i;
	for(i=31;i>0;i--)
	{	    
	 printf("%d",sigismember(&oldset,i));   
	}
	printf("\n");
}
void sig_handler(int signo)
{
    if(signo == SIGINT)
    {
	int j;
	for(j=0;j<=10;j++)
	   {
	    printf("%d\n",j);
	    sleep(1);
	   }
    }else if(signo == SIGTSTP)
    {
	int j;
	for(j=0;j<=10;j++)
	   {
	    printf("%d\n",j);
	    sleep(1);
	   }

    }
}
int main(void)
{
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    sigset_t oldset;
    sigprocmask(SIG_UNBLOCK,&set,&oldset);
    print_set(oldset);
    sigprocmask(SIG_UNBLOCK,&set,&oldset);
    print_set(oldset);
    if(signal(SIGINT,sig_handler)==SIG_ERR)
    {
	fprintf(stderr,"signal: %s\n",strerror(errno));
	exit(1);
    }
    if(signal(SIGTSTP,sig_handler)==SIG_ERR)
    {
	fprintf(stderr,"signal2: %s\n",strerror(errno));
	exit(1);
    }

    while(1)
    pause();
}
