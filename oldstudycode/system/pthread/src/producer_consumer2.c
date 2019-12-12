#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
int flag=0;
int global=10;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
void *th_producer(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);

		while(global > 0)
		{
			pthread_mutex_unlock(&lock);
			usleep(200);
			pthread_mutex_lock(&lock);
		}
		int val=global;
		val+=1;
		sleep(1);
		printf("%lxI produce:%dto%d\n",pthread_self(),global,val);
		global=val;
		while(!flag)
		{
			pthread_mutex_unlock(&lock);
			usleep(20);
			pthread_mutex_lock(&lock);
		}
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&lock);
		usleep(20);
	}
}
void *th_consumer(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		while(global <= 0)
		{
			flag++;
			pthread_cond_wait(&cond,&lock);
			flag--;
		}
		int val=global;
		val-=1;
		usleep(500*1000);
		printf("%lxI consume:%dto%d\n",pthread_self(),global,val);
		global=val;
		pthread_mutex_unlock(&lock);
	}

}
int main(void)
{
	pthread_t consumer1,consumer2,producer,producer2;
	if(pthread_create(&consumer1,NULL,th_consumer,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&consumer2,NULL,th_consumer,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&producer,NULL,th_producer,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&producer2,NULL,th_producer,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	pthread_join(consumer1,NULL);
	pthread_join(producer,NULL);
	pthread_join(consumer2,NULL);
	pthread_join(producer2,NULL);
	return 0;
}
