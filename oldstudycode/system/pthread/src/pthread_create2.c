#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
void *th_1(void *arg)
{
	int *val = (int *)arg;
	int i=0;
	while(1)
	{

 	    printf("the val receive : %d i am %d th_id:%lu\n",*val,getpid(),pthread_self());
		sleep(1);
        i++;
		if(i ==10)
		{
			break;
		}
	
     }
	pthread_exit((void *)(*val+1));
}
int main(void)
{
	pthread_t th1;
	int num = 99;
	pthread_create(&th1,NULL,th_1,(void *)&num);
    int ret;
    pthread_join(th1,(void **)&ret);
	printf("I get the thread information: %d\n",ret);
	pause();
	return 0;
}
