#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
void *th_fun(void* arg)
{
	printf("thread %lu started!\n",pthread_self());
	pause();
}
int main(void)
{

	pthread_attr_t th_attr;
	pthread_attr_init(&th_attr);
	//获取线程属性
	int detachState;
	if(pthread_attr_getdetachstate(&th_attr,&detachState)!=0)
	{
		fprintf(stderr,"getDATACH: %s\n",strerror(errno));
		exit(1);

	}
	//分析线程属性
	if(detachState == PTHREAD_CREATE_JOINABLE)
	{
		printf("thread is joinable!\n");
	}
	if(detachState == PTHREAD_CREATE_DETACHED)
	{
		printf("thread is detacher!\n");
	}

	if(pthread_attr_setdetachstate(&th_attr,PTHREAD_CREATE_DETACHED)!=0)
	{
		fprintf(stderr,"set_detach: %s\n",strerror(errno));
		exit(1);

	}
	if(pthread_attr_getdetachstate(&th_attr,&detachState)!=0)
	{
		fprintf(stderr,"getDATACH: %s\n",strerror(errno));
		exit(1);

	}
	//分析线程属性
	if(detachState == PTHREAD_CREATE_JOINABLE)
	{
		printf("thread is joinable!\n");
	}
	if(detachState == PTHREAD_CREATE_DETACHED)
	{
		printf("thread is detacher!\n");
	}
	pthread_t th;
	pthread_t ths[40000];
    int counter =0;
	while(1)
	{
	//pthread_t th;
	if(pthread_create(&th,&th_attr,th_fun,NULL)!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		/*int i;
		for(i=0;i<counter;i++)
		{
			//pthread_join(ths[i],NULL);
		}*/
		break;

	}
	//ths[counter]=th;
	counter++;
	}
	printf("already created %d threads\n",counter);
	if(pthread_create(&th,&th_attr,th_fun,NULL)!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	printf("creat new thread success\n");
	pthread_attr_destroy(&th_attr);
	pause();
	return 0;
}
