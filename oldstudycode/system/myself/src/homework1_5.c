#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
int main(void)
{
    pid_t pid;
    pid_t pid_b;
    pid_t pid_a=getpid();
    int i;
    for(i=0;i<3;i++)
    {
	if((pid=fork())<0)
	{
	    fprintf(stderr,"fork: %s\n",strerror(errno));
	    exit(1);
	}else if(pid > 0)
	{
	    if(i==0)
	    {
		
		break;
	    }
	    if(i == 2 && getppid() == pid_a)
	    {
		setpgid(0,0);
	    }
	}
	else
	{   
	    if(i == 0)
	    {
		setpgid(pid,pid);
		pid_b = pid;
	    }
	    if(i == 1)
	    {
		setpgid(pid,pid_b);
	    }
	    if(i == 2 && getppid()==pid_a)
	    {
		setpgid(pid,getppid());
	    }

	}
    }
    printf("pid=: %d,ppid=: %d,pgid=: %d\n",getpid(),getppid(),getpgid(0));
    pause();
    return 0;
}
