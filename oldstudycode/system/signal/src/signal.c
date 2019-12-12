#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>

int main(void)
{
	int i;
	//for(i =1;i<=31;i++)
	/*{
		if(signal(i,SIG_IGN)==SIG_ERR)
		{
			fprintf(stderr,"signal: %s\n",strerror(errno));
			printf("signal %d is not ignored!\n",i);
			//exit(1);
		}
	}*/
	if(signal(SIGINT,SIG_IGN)==SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	sleep(5);
	if(signal(SIGINT,SIG_DFL)==SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	while(1)
	{

	}
	return 0;
}
