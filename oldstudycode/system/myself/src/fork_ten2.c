#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

pid_t  pid;
int i=0;
void fork_n1()
{
		pid = fork();
		if(pid > 0)
		{
			if(i==9)
			{
				return ;
			}
			i++;
			fork_n1();
		}else
		{
			printf("%d , %d\n",getpid(),getppid());
			

		}

}
void fork_n()
{
		pid = fork();
		if(pid > 0)
		{
		}else
		{
			
			if(i==10)
			{
				return ;
			}
			i++;
			printf("%d , %d\n",getpid(),getppid());
			fork_n();

		}

}
int main(void)
{
	//fork_n1();
	fork_n();
    pause();
	return 0;
}
