#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
void *th_fun(void *arg)
{

	pthread_exit(NULL);
}
int main(void )
{
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int detachstate;
	if(pthread_attr_getdetachstate(&attr,&detachstate)!=0)
	{
		fprintf(stderr,"getstate: %s\n",strerror(errno));
		exit(1);
	}
	if(detachstate == PTHREAD_CREATE_JOINABLE)
	{
		printf("thread is joinable!\n");
	}
	else if(detachstate == PTHREAD_CREATE_DETACHED)
	{
		printf("thread is detached !\n");
	}else
	{
		printf("unknow attribute!\n");
	}
	//pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	int counter =0;
	int index = 0;
	pthread_t th[5000];
	while(1)
	{
	if(pthread_create(&th[index],&attr,th_fun,NULL)!=0)
	{
		fprintf(stderr,"create: %s\n",strerror(errno));
		int i;
		for(i=0;i<index;i++)
		{
			pthread_join(th[i],NULL);
		}
		index=0;
        continue;
	}
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>counter:%d\n",counter);
     counter++;
	 index++;
	//pthread_join(th,NULL);
	}
    printf("counter: %d\n",counter);
	pthread_attr_destroy(&attr);
	return 0;
}
