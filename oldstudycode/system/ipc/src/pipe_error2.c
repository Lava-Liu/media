#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
void set_fl(int fd,int flag)
{
	int oldflag=fcntl(fd,F_GETFL);
	int newflag=flag|oldflag;
	if(fcntl(fd,F_SETFL,newflag)<0)
	{
		fprintf(stderr,"fcntl: %s\n",strerror(errno));
		exit(1);
	}
}
void sig_handler(int signo)
{
	if(signo == SIGPIPE)
	{
		printf("%d receive sigpipe signal!\n",getpid());
	}
}
int main(void)
{
	if(signal(SIGPIPE,sig_handler) == SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	int fd[2];
	if(pipe(fd)<0)
	{
		fprintf(stderr,"pipe: %s\n",strerror(errno));
		exit(1);
		
	}
	set_fl(fd[0],O_NONBLOCK);
	set_fl(fd[1],O_NONBLOCK);
	pid_t pid;
	if((pid =fork())<0)
	{
		fprintf(stderr,"fork: %s\n",strerror(errno));
		exit(1);

	}else if(pid == 0)
	{
		close(fd[1]);
		//pause();
		//close(fd[0]);
		sleep(10);
		ssize_t n_read;
		  char buffer[65536]={0};

		  if((n_read=read(fd[0],buffer,65536))<0)
		  {
		  fprintf(stderr,"read: %s\n",strerror(errno));
		  exit(1);
		  }
		  printf("nread: %d,buffer:%s\n",n_read,buffer);
		  pause();
	}else
	{

		close(fd[1]);
		//sleep(1);
		/*while(1)
		{
			char buffer[256] = {0};
			strcpy(buffer,"Message");
			int len=strlen(buffer);
			if(write(fd[1],buffer,len)!=len)
			{
				fprintf(stderr,"write: %s\n",strerror(errno));
				exit(1);
			}
		}*/
		//close(fd[1]);
		/*int counter=0;
		while(1)
		{
			if(write(fd[1],"a",1)!=1)
			{
				fprintf(stderr,"write: %s\n",strerror(errno));
				//exit(1);
				break;
			}
			counter++;
			printf("Already write %d bytes!\n",counter);
		}*/
		wait(NULL);
	}




	return 0;
}
