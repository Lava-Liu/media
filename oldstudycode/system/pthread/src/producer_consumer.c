#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
//生产者消费者问题
//供不应求
int global=0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond3 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond4 = PTHREAD_COND_INITIALIZER;

void *th_producer(void *arg)
{
	while(1)
	{
		if(global > 2)
		{
		    pthread_mutex_lock(&mutex);
			pthread_cond_wait(&cond2,&mutex);
		    pthread_mutex_unlock(&mutex);
		}else
		{
		pthread_mutex_lock(&mutex);
		}

		int var = global;
		sleep(1);
		var+=10;
		printf("%lx producer: ,%d to %d\n",pthread_self(),global,var);
		global = var;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
		usleep(50);
	}
}
void *th_consumer(void *arg)
{
	while(1)
	{
		if(global == 1)
		{
		  pthread_mutex_lock(&mutex);
		  pthread_cond_signal(&cond2);
		pthread_mutex_unlock(&mutex);
		}else
		{
	 	  pthread_mutex_lock(&mutex);
		  pthread_cond_wait(&cond,&mutex);
		}
		int var =global;
		sleep(1);
		var-=1;
		printf("%lx consumer: ,%d to %d\n",pthread_self(),global,var);
		global =var;
		pthread_mutex_unlock(&mutex);
		usleep(50);
	}
}

int main(void)
{
	pthread_t pro,con1,con2,con3;
	if(pthread_create(&pro,NULL,th_producer,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&con1,NULL,th_consumer,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&con2,NULL,th_consumer,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&con3,NULL,th_consumer,NULL)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	pthread_join(pro,NULL);
	pthread_join(con1,NULL);
	pthread_join(con2,NULL);
	pthread_join(con3,NULL);

	return 0;
}

