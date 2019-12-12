#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>
void *th_tortoise(void* arg)
{
	int i=0;
	while(1)
	{
		sleep(1);
		i=i+5;
		printf("I am tortoise I run :%d\n",i);
		if(i>=100)
		{
			break;
		}

	}
	pthread_exit((void *)"tortoise");
}
void *th_rabbit(void* arg)
{
       int i;
	   int j;
	   while(1)
	   {
		   sleep(1);
		   srand((unsigned)time(NULL)+1);
		   j=rand()%10;
		   i=i+j;
		   printf("I am rabbit I run :%d\n",i);
		   if(i>=100)
		   {
              break;
		   }
	   }
	pthread_exit((void *)"rabbit");
}
void *th_rabbit_del(void *arg)
{
	pthread_t th2 = (pthread_t)arg;
	char *p;
	if(pthread_join(th2,(void**)&p)!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}else
	{
		printf("%s  win !\n",p);
		exit(1);
	}

}
void *th_tortoise_del(void *arg)
{
	pthread_t th = (pthread_t)arg;
	char *p;
	if(pthread_join(th,(void**)&p)!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}else
	{
		printf("%s win !\n",p);
		exit(1);
	}

}
int main(void)
{
    pthread_t th,th2,th3,th4;

	if(pthread_create(&th,NULL,th_tortoise,NULL))
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&th2,NULL,th_rabbit,NULL))
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&th3,NULL,th_rabbit_del,(void *)th2))
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&th4,NULL,th_tortoise_del,(void *)th))
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	pause();


	return 0;
}
