#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_init(&lock,PTHREAD_MUTEX_INITIALIZER);
//
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
int product=0;
int flag=0;
void *th_producer(void *arg)
{
	int i;
	while(1)
	{
		pthread_mutex_lock(&lock);
		while(flag>0)
		{	
			pthread_mutex_unlock(&lock);
			usleep(20);
			pthread_mutex_lock(&lock);
		}
		i=product;
		i=i+2;
		
		sleep(1);
		printf("I am producer:product: %d to %d\n",product,i);
		product=i;
		i=product;
		
		pthread_cond_broadcast(&cond);
		flag=2;
		
		pthread_mutex_unlock(&lock);
	}
	pthread_exit(NULL);
}
void *th_consumer(void *arg)
{
	int i;
	while(1)
	{
		
		pthread_mutex_lock(&lock);
		flag-=1;
		if(flag == 0)
		{
		  pthread_cond_wait(&cond,&lock);
		  flag=0;
		}
		i=product;
		i=i-1;
		flag=flag-1;
		sleep(1);
		printf("I am consumer:product: %d to %d\n",product,i);
		product=i;
		pthread_mutex_unlock(&lock);
	}
	pthread_exit(NULL);

}
int main(void)
{
    pthread_t producer,consumer1,consumer2;
	if(pthread_create(&producer,NULL,th_producer,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
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
	pthread_join(producer,NULL);
	pthread_join(consumer1,NULL);
	pthread_join(consumer2,NULL);

	return 0;
}
