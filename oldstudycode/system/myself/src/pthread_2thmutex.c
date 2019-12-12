#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *th_1(void *arg)
{
	pthread_mutex_lock(&mutex);
	int fd=open("a.txt",O_CREAT|O_WRONLY,0777);
	lseek(fd,0,SEEK_END);
	char buffer[256]="aaaaaaaa";
	int len=strlen(buffer);
	if(write(fd,buffer,len)!=len)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);
	}
	close(fd);
	pthread_mutex_unlock(&mutex);
}
void *th_2(void *arg)
{
	pthread_mutex_lock(&mutex);
	int fd=open("a.txt",O_CREAT|O_WRONLY,0777);
	lseek(fd,0,SEEK_END);
	char buffer[256]="bbbbbbbbbbb";
	int len=strlen(buffer);
	if(write(fd,buffer,len)!=len)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);
	}
	close(fd);
	pthread_mutex_unlock(&mutex);
}
int main(void)
{
	pthread_t th1,th2;
	if(pthread_create(&th1,NULL,th_1,(void *)1)<0)
	{
		fprintf(stderr,"pth_create: %s\n",strerror(errno));
		exit(1);
	}
	if(pthread_create(&th2,NULL,th_2,(void *)1)<0)
	{
		fprintf(stderr,"pth_create: %s\n",strerror(errno));
		exit(1);
	}
	pause();
	return 0;
}

