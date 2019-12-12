#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>

void cleanup1(void *arg)
{
	printf("cleanup1,arg: %s\n",(char *)arg);
}
void cleanup2(void *arg)
{

	printf("cleanup2,arg: %s\n",(char *)arg);
}
void cleanup3(void *arg)
{

	printf("cleanup3,arg: %s\n",(char *)arg);
}
void *th_fun(void *arg)
{
	pthread_cleanup_push(cleanup1,"first");
	pthread_cleanup_push(cleanup2,"second");
	pthread_cleanup_push(cleanup3,"third");
	printf("in thread ,arg : %s\n",(char *)arg);
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(1);
	return (void *)("finish");
}
int main(void)
{
	pthread_t th;
	if(pthread_create(&th,NULL,th_fun,(void *)"start")!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	char *str=NULL;
	pthread_join(th,(void **)&str);
	printf("receive %s\n",str);
	return 0;

}
