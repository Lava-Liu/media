#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"%s [normal|error|recursive]\n",argv[0]);
		exit(1);
	}
	//初始化互斥量属性
	pthread_mutex_t mutex;
	pthread_mutexattr_t mutexattr;
	pthread_mutexattr_init(&mutexattr);
	if(!strcmp(argv[1],"normal"))
	{
		pthread_mutexattr_settype(&mutexattr,PTHREAD_MUTEX_NORMAL);
	}
	else if(!strcmp(argv[1],"error"))
	{
		pthread_mutexattr_settype(&mutexattr,PTHREAD_MUTEX_ERRORCHECK);
	}
	else if(!strcmp(argv[1],"recursive"))
	{
		pthread_mutexattr_settype(&mutexattr,PTHREAD_MUTEX_RECURSIVE);
	}
	else
	{
		printf("unknow argument!\n");
		exit(1);
	}
	//把互斥量属性设置到互斥量上
	pthread_mutex_init(&mutex,&mutexattr);
	//开始上锁，解锁过程
	if(pthread_mutex_lock(&mutex)!=0)
	{
		fprintf(stderr,"lock error!\n");
	}else
	{
		printf("lock success!\n");
	}
	if(pthread_mutex_lock(&mutex)!=0)
	{
		fprintf(stderr,"lock error!\n");
	}else
	{
		printf("lock success!\n");
	}
	pthread_mutex_unlock(&mutex);
	pthread_mutex_unlock(&mutex);
	pthread_mutexattr_destroy(&mutexattr);	
	pthread_mutex_destroy(&mutex);
	printf("mutedx handler finished!\n");   
	return 0;
}
