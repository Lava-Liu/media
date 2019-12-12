#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage: %s [types]\n",argv[0]);
		exit(1);
	}
    int type;
	if(!strcmp(argv[1],"normal"))
	{
		type=PTHREAD_MUTEX_NORMAL;
	}else
	if(!strcmp(argv[1],"error"))
	{
		type=PTHREAD_MUTEX_ERRORCHECK;
	}else
	if(!strcmp(argv[1],"recursive"))
	{
		type=PTHREAD_MUTEX_RECURSIVE;
	}else
	{
		fprintf(stderr,"unknow type!\n");
		exit(1);
	}
 
	//初始化互斥锁属性
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr,type);
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex,&attr);
	//互斥操作
	if(pthread_mutex_lock(&mutex)!=0)
	{
		fprintf(stderr,"lock: %s\n ",strerror(errno));
		exit(1);
	}else
	{
		printf("lock success!\n");
	}
	int err;
	if((err=pthread_mutex_lock(&mutex))!=0)
	{
		fprintf(stderr,"lock: %s\n ",strerror(err));
		exit(1);
	}else
	{
		printf("lock success!\n");
	}
	pthread_mutex_unlock(&mutex);
	pthread_mutex_unlock(&mutex);

	return 0;
}
