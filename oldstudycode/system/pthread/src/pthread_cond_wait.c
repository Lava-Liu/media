#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>

int sum;


void *th_cal(void *arg)
{
	int i;
	for(i =1;i<=100;i++)
	{
		int var = sum;
		usleep(50*1000);
		var += i;
		sum = var;
	}
}
void *th_get(void *arg)
{
	int var = sum;
	printf("result: %d\n",var);
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
