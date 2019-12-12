#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
void *th_1(void* arg)
{
	int val = (int )arg;
	printf("I am thread i get: %d i am going to die !\n",val);
}
int main(void)
{
	//获取分离属性
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int detachstate;
	pthread_attr_getdetachstate(&attr,&detachstate);
	if(detachstate == PTHREAD_CREATE_JOINABLE)
	{
		printf("thread is JOINABLE!\n");
	
	}else if(detachstate == PTHREAD_CREATE_DETACHED)
	{
		printf("therad is detached\n");

	}else 
	{
		printf("unknow attribute!\n");
	}
	
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_attr_getdetachstate(&attr,&detachstate);
	
	if(detachstate == PTHREAD_CREATE_JOINABLE)
	{
		printf("thread is JOINABLE!\n");
	
	}else if(detachstate == PTHREAD_CREATE_DETACHED)
	{
		printf("therad is detached\n");

	}else 
	{
		printf("unknow attribute!\n");
	}
	pthread_t th1;
	pthread_create(&th1,&attr,th_1,(void *)11);
	

	return 0;
}
