#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>

void *th_fun(void *arg)
{
	int *a=(int *)arg;
	printf("%d  , %lu\n",*a+10,pthread_self());
	pthread_exit(NULL);
}
int main(void)
{
	int a=10;
	pthread_t th;
	if(pthread_create(&th,NULL,th_fun,(void *)&a)!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	pthread_join(th,NULL);
	printf("in main thread %d\n",a);
	pause();


	return 0;
}
