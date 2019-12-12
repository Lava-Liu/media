#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
int sum=0;
int flag=0;
void *th_cal(void *arg)
{
	pthread_mutex_lock(&lock);
	int i=1;

	for(i;i<=100;i++)
	{
		int val = sum;
		val+=i;
		usleep(20*1000);
		sum=val;
	}
	//发通知
    while(flag==0)
	{
		pthread_mutex_unlock(&lock);
		usleep(20);
		pthread_mutex_lock(&lock);
	}
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&lock);
	
	pthread_exit(NULL);
}
void *th_get(void *arg)
{
	pthread_mutex_lock(&lock);
	//等待通知
	flag=1;
	pthread_cond_wait(&cond,&lock);
	
	

	sleep(1);
	int val=sum;
	printf("sum: %d\n",val);
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}
int main(void)
{

	pthread_t cal,get;
	if(pthread_create(&cal,NULL,th_cal,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&get,NULL,th_get,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	pthread_join(cal,NULL);
	pthread_join(get,NULL);

	return 0;
}
