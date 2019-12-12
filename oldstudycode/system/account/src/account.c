#include  "account.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>
#include <assert.h>


//初始化账户
Account *init(long id,double balance)
{
	Account *act = (Account *)malloc(sizeof(Account));
	assert(act != NULL);
	act->id = id;
	act->balance = balance;
	pthread_rwlock_init(&act->rwlock,NULL);
	return act;
}
//销毁账户
void destroy(Account *act)
{
	assert(act != NULL);
	pthread_rwlock_destroy(&act->rwlock);
	free(act);
}
//取款
double withdraw(Account *act, double amount)
{
	assert(act != NULL);
	pthread_rwlock_wrlock(&act->rwlock);
	double balance =act -> balance;
	if(amount < 0 || balance < amount )
	{
		return 0;
	}
	sleep(1);
	balance -=amount;
	act->balance = balance;
	pthread_rwlock_unlock(&act->rwlock);
	return amount;
}
//存款
double deposit(Account *act , double amount)
{
	assert(act != NULL);
	pthread_rwlock_wrlock(&act->rwlock);
	double balance = act->balance;
	if(amount < 0)
	{
		return 0;
	}
	sleep(1);
	balance += amount;
	act->balance = balance;
	pthread_rwlock_unlock(&act->rwlock);
	return amount;
}
//察看余额
double getBalance(Account *act)
{
	assert(act != NULL);
	pthread_rwlock_rdlock(&act->rwlock);
	double balance = act->balance;
	sleep(2);
	pthread_rwlock_unlock(&act->rwlock);
	return balance;
}



