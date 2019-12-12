#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

pthread_mutex_t mutex;
int global;
void *th_fun(void *arg)
{
	printf("%lu stated!\n",pthread_self());
	while(1)
	{
		pthread_mutex_lock(&mutex);
		int var = global;
		var++;
		sleep(1);
		printf("%lu set global %d --> %d\n",pthread_self(),global,var);
		global = var;
		pthread_mutex_unlock(&mutex);
		usleep(50);//微妙
	}
	printf("%lu finished !\n,",pthread_self());
}
int main(void)
{
	pthread_mutex_init(&mutex,NULL);
	pthread_t th1,th2;
	if(pthread_create(&th1,NULL,th_fun,NULL)!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&th2,NULL,th_fun,NULL)!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	//pthread_mutex_destroy(&mutex);
	pause();
	return 0;
}
