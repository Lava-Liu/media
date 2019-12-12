#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>

void *th_fun(void *arg)
{
	//将参数类型还原
	char *str = (char *)arg;

	printf("thread1,pid: %d,tid: %lu\n",getpid(),pthread_self());
	printf("receive an arg: %s\n",str);
}
void *th_fun2(void *arg)
{
	int *num = (int *)arg;
	printf("thread2,pid: %d,tid: %lu\n",getpid(),pthread_self());
	printf("receive an arg: %d\n",*num);

}
int main(void)
{
	pthread_t th1,th2;

	char *str = "message";
	if(pthread_create(&th1,NULL,th_fun,(void *)str)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	int num=100;
	if(pthread_create(&th2,NULL,th_fun2,(void *)&num)!=0)
	{
		fprintf(stderr,"th_creat: %s\n",strerror(errno));
		exit(1);
	}
	pause();
	return 0;
}
