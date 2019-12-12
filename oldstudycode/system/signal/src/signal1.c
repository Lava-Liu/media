#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
int main(void )
{
    int i;
    for(i=1;i<=31;i++)
    {
	if(signal(i,SIG_IGN)==SIG_ERR)
	{
	    printf("%d\n",i);
	    fprintf(stderr,"signal: %s\n",strerror(errno));
	    continue;
	}
    }
    if(signal(SIGINT,SIG_DFL)==SIG_ERR)
    {
	    fprintf(stderr,"signal: %s\n",strerror(errno));
	    exit(1);
    }
    pause();
    return 0;
}
