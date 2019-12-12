#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
pthread_t th1,th2;
void *th_1(void *arg)
{
	if(pthread_equal(pthread_self(),th1))
	{
	char *string = (char *)arg;
	printf("I receive the arg: %s\n",string);
	pthread_exit(NULL);
	}
	if(pthread_equal(pthread_self(),th2))
	{
	int a = (int )arg;
	printf("I receive the arg: %d\n",a);
	pthread_exit(NULL);
	}
}
int main(void)
{
    char *str = "beautiful!";
	if(pthread_create(&th1,NULL,th_1,(void *)str)!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&th2,NULL,th_1,(void *)100)!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	return 0;
}
