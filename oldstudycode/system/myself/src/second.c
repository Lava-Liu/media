#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
void sig_handler(int signo)
{
	if(signo == SIGALRM)
	{
		static int sec=0;
		static int utim=0;
		utim++;
		static int min=0;
		if(utim == 1000)
		{
			utim=0;
			sec++;
		}
		if(sec == 60)
		{
			sec=0;
			min++;
		}
		printf("\033[1H\033[2J");
		fflush(stdout);
		printf("%02d:%02d:%03d\n",min,sec,utim);
		
	}

	//ualarm(1,100*1000);
}
int main(void)
{
	if(signal(SIGALRM,sig_handler)==SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		
		exit(1);
	}
	ualarm(1,1*1000);
	while(1)
		pause();
	return 0;
}
