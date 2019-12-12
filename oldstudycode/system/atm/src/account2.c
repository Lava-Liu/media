#include "account.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <memory.h>
#include <pthread.h>
//初始化账户
Account *init(char *id,double amount)
{
	Account *act=(Account *)malloc(sizeof(Account));
	assert(act != NULL);
	memset(act,0,sizeof(Account));
	strcpy(act->id,id);
	act->balance=amount;
	pthread_rwlock_init(&act->lock,NULL);
	return act;
}
//销毁账户
void destroy(Account *act)
{
	assert(act != NULL);
	pthread_rwlock_destroy(&act->lock);
	free(act);
	act=NULL;
}
//取款
double withdraw(Account *act,double amount)
{
	assert(act != NULL);
	if(amount < 0 || amount > act->balance)
	{
		return 0;
	}
	double balance = act->balance;
	balance-=amount;
	sleep(1);
	act->balance = balance;
	return amount;

}
//存款
double deposit(Account *act,double amount)
{
	assert(act != NULL);
	int balance = act->balance;
	balance+=amount;
	sleep(3);
	act->balance = balance;
	return amount;
}
//查询余额
double getBalance(Account *act)
{
	assert(act != NULL);
	int balance = act->balance;
	sleep(2);
	return balance;

}


