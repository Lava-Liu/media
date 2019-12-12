#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>

int sum;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


void *th_cal(void *arg)
{
	pthread_mutex_lock(&mutex);
	int i;
	for(i =1;i<=100;i++)
	{
		int var = sum;
		usleep(50*1000);
		var += i;
		sum = var;
	}
	pthread_cond_broadcast(&cond);
	pthread_mutex_unlock(&mutex);
}
void *th_get(void *arg)
{
	pthread_mutex_lock(&mutex);
	pthread_cond_wait(&cond,&mutex);
	int var = sum;
	printf("result: %d\n",var);
	pthread_mutex_unlock(&mutex);
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
