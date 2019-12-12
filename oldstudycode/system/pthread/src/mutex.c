#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
int global=0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *th_1(void *arg)
{
	int i=0;
	for(i=0;i<10;i++)
	{
		pthread_mutex_lock(&mutex);
		int val =global;
		val++;
		sleep(1);
		printf("th_1:Change global from %d to %d\n",global,val);
		global =val;
		pthread_mutex_unlock(&mutex);
		usleep(50);

	}
	pthread_exit(NULL);
}
void *th_2(void *arg)
{
	int i;
	for(i =0;i<10;i++)
	{
		pthread_mutex_lock(&mutex);
		int val =global;
		val--;
		sleep(1);
		printf("th_2:Change global from %d to %d\n",global,val);
		global =val;
		pthread_mutex_unlock(&mutex);
		usleep(50);
	}
	pthread_exit(NULL);
}
int main(void)
{
	pthread_t th1,th2;
	if(pthread_create(&th1,NULL,th_1,NULL)!=0)
	{
		fprintf(stderr,"create: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&th2,NULL,th_2,NULL)!=0)
	{
		fprintf(stderr,"create: %s\n",strerror(errno));
		exit(1);
	}
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	return 0;
}
