#include "account.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
pthread_t th1,th2,th3,th4,th5;
void *th_1(void *arg)
{
    Account *act=(Account *)arg;
	if(pthread_equal(pthread_self(),th1))
	{
         deposit(act,1000.0);
        pthread_exit(NULL);
	}
	else if(pthread_equal(pthread_self(),th2))
	{
         withdraw(act,1000.0);
        pthread_exit(NULL);
	}
	else if(pthread_equal(pthread_self(),th3))
	{
         deposit(act,1000.0);
        pthread_exit(NULL);
	}
	else if(pthread_equal(pthread_self(),th4))
	{
         getbalance(act);
        pthread_exit(NULL);
	}
}
int main(void )
{
	Account *act=init(10086,10000.0,"liuwei");
	pthread_create(&th1,NULL,th_1,(void *)act);
	pthread_create(&th2,NULL,th_1,(void *)act);
	pthread_create(&th3,NULL,th_1,(void *)act);
	pthread_create(&th4,NULL,th_1,(void *)act);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);
	pthread_join(th4,NULL);

	return 0;
}
