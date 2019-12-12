#include  <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
/*void add_c()
  {
  if((pid=fork())<0)
  {
  fprintf(stderr,"fork: %s\n",strerror(errno));
  exit(1);
  }else if(pid == 0)
  {
  fprintf(stderr,"fork: %s\n",strerror(errno));
  exit(0);
  }else
  {
  fprintf(stderr,"fork: %s\n",strerror(errno));
  exit(0);

  }

  }
  int main(void)
  {
  pid_t pid;
  if((pid=fork())<0)
  {
  fprintf(stderr,"fork: %s\n",strerror(errno));
  exit(1);
  }else if(pid == 0)
  {
  if((pid=fork())<0)
  {
  fprintf(stderr,"fork: %s\n",strerror(errno));
  exit(1);
  }else if(pid == 0)
  {
  printf("%d:%d\n",getpid(),getppid());
  }else
  {
  printf("%d:%d\n",getpid(),getppid());
  exit(0);
  }

  }else

  {
  wait(NULL);
  printf("%d:%d\n",getpid(),getppid());
  if((pid=fork())<0)
  {
  fprintf(stderr,"fork: %s\n",strerror(errno));
  exit(1);
  }else if(pid == 0)
  {
  printf("%d:%d\n",getpid(),getppid());
  exit(0);

  }else
  {
  wait(NULL);
  printf("%d:%d\n",getpid(),getppid());
  if((pid=fork())<0)
  {
  fprintf(stderr,"fork: %s\n",strerror(errno));
  exit(1);
  }else if(pid == 0)
  {
  fprintf(stderr,"fork: %s\n",strerror(errno));
  exit(0);
  }else
  {
  fprintf(stderr,"fork: %s\n",strerror(errno));
  exit(0);

}

}

}

return 0;
}*/
int main(void)
{
	pid_t pid;
	int i;
	int first_pid = getpid();
	for(i=0;i<3;i++)
	{
		if((pid=fork())<0)
		{
			fprintf(stderr,"fork: %s\n",strerror(errno));
			exit(1);
		}else if(pid == 0 )

		{
			if(i==1)
			{
				break;
			}
		}
		if(getppid() == first_pid && (i == 1 ))
		{
			break;
		}

	}
	printf("%d:%d\n",getpid(),getppid());
	pause();
	return 0;

}

