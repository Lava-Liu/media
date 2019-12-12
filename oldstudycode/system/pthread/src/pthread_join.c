#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
void *th_fun(void *arg)
{
	int val = (int)arg;
	printf("Received value: %d\n",val);
	pthread_exit((void*)(val+100));
	return (void *)(val*val);
}
int main(void)
{
	pthread_t th;
	if(pthread_create(&th,NULL,th_fun,(void *)11) != 0)
	{
		fprintf(stderr,"th_create; %s\n",strerror(errno));
		exit(1);
	}
	int ret;
	pthread_cancel(th);
	pthread_join(th,(void **)&ret);
	printf("result of thread is: %d\n",ret);
	return 0;
}
