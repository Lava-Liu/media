#include "account.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <pthread.h>





Account *init(long id,double balance,char *name)
{
	Account *act=(Account *)malloc(sizeof(Account));
	if(act == NULL)
	{
		return NULL;
	}
	act->ID=id;
	act->balance=balance;
	strcpy(act->name,name);
	pthread_rwlock_init(&act->rwlock,NULL);
	return act;

}
void destroy_account(Account *act)
{
	assert(act != NULL);
	pthread_rwlock_destroy(&act->rwlock);
	free(act);
}
int withdraw(Account *act,double amount)
{
	assert(act != NULL);
	pthread_rwlock_wrlock(&act->rwlock);
	double number=act->balance;
	if(amount < 0||number < amount)
	{
		exit(1);
	}else 
	{
		number-=amount;
		act->balance = number;
	    pthread_rwlock_unlock(&act->rwlock);
		return 1;
	}
	
}
int deposit(Account *act,double amount)
{
	assert(act != NULL);
	pthread_rwlock_wrlock(&act->rwlock);
	double num=act->balance;
	num+=amount;
	act->balance=num;
	pthread_rwlock_unlock(&act->rwlock);
	return 1;

}
double  getbalance(Account *act)
{
	assert(act != NULL);
	pthread_rwlock_rdlock(&act->rwlock);
	printf("name:%s Id: %ld balance: %lf\n",act->name,act->ID,act->balance);
	pthread_rwlock_unlock(&act->rwlock);
	return act->balance;
}






