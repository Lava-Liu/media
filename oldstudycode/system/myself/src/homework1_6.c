#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		printf("I am: %d i get SIGINT\n",getpid());
	}else if(signo == SIGTSTP)
	{
		printf("I am: %d i get SIGTSTP\n",getpid());
	}
}
int main(void)
{
  if(signal(SIGINT,SIG_IGN)==SIG_ERR)
  {
	  fprintf(stderr,"signal: %s\n",strerror(errno));
	  exit(1);
  }
  pid_t pid;
  if( (pid =fork())<0)
  {
	  fprintf(stderr,"fork:  %s\n",strerror(errno));
	  exit(1);
  }
  else if(pid == 0)
  {
    if(signal(SIGINT,sig_handler)==SIG_ERR)
    {
	  fprintf(stderr,"signal: %s\n",strerror(errno));
	  exit(1);
    }
    if(signal(SIGTSTP,sig_handler)==SIG_ERR)
    {
	  fprintf(stderr,"signal: %s\n",strerror(errno));
	  exit(1);
    }
	  		
  }
  else
  {

    if(signal(SIGINT,sig_handler)==SIG_ERR)
    {
	  fprintf(stderr,"signal: %s\n",strerror(errno));
	  exit(1);
    }
  }
  while(1)
	  pause();
}
