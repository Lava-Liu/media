#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>
pthread_t tortoise,rabbit;
void *th_fun(void *argc)
{
	if(pthread_equal(pthread_self(),tortoise))
	{
		int a=0;
		int sum=0;
		while(1)
		{
			usleep(500*1000);
			sum=sum+5;
			printf("I am tortoise I run: %d\n",sum);
			if(sum >= 100)
			{
				break;
			}
		}
		pthread_cancel(rabbit);
		pthread_exit((void *)"tortoise");
	}
	if(pthread_equal(pthread_self(),rabbit))
	{
		int b=0;
		int su=0;
		while(1)
		{
			usleep(500*1000);
            srand((unsigned)time(NULL)+1);
			b=rand()%9;
     		su=su+b;
			printf("I am rabbit I run : %d\n",su);
			if(su >= 100)
			{
               break;
			}
		}
		pthread_cancel(tortoise);
		pthread_exit((void *)"rabbit");

	}

}
int main(void)
{
	if(pthread_create(&tortoise,NULL,th_fun,(void *)"start")!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&rabbit,NULL,th_fun,(void *)"start")!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	char *str=NULL;
	pthread_join(rabbit,(void **)&str);
	pthread_join(tortoise,(void **)&str);
	printf("The winer is: %s\n ",str);
	return 0;
}

