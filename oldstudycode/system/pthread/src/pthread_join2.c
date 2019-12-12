#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
void *clean1(void *arg)
{
	//char *str=(char *)arg;
	printf("clean: %s\n",(char *)arg);
}
void *th_1(void *arg)
{
	pthread_cleanup_push(clean1,"first");
	pthread_cleanup_push(clean1,"second");
	pthread_cleanup_push(clean1,"third");
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(1);
	return (void *)("finish");
}
int main(void)
{
	pthread_t th1;
	if(pthread_create(&th1,NULL,th_1,NULL)!=0)
	
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
	char *str;
	pthread_join(th1,(void **)&str);
	printf("pthread cleanup: %s\n",str);
    
	return 0;
}
