#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
void *th_1(void *arg)
{

}
int main(void)
{
	//定义一个线程标识
	pthread_t th1,th2;
    int counter=0;
	while(1)
	{
		counter++;
	if(pthread_create(&th1,NULL,th_1,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		printf("counter: %d\n",counter);
		break;
	}
	}

	return 0;
}

