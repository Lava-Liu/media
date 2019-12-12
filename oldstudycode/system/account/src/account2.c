#include  "account.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>
#include <assert.h>
#include "pv.h"

//初始化账户
Account *init(long id,double balance)
{
	Account *act = (Account *)malloc(sizeof(Account));
	assert(act != NULL);
	act->id = id;
	act->balance = balance;
	act->semid = I(1,1);
	if(act->semid < 0)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(1);
	}
	return act;
}
//销毁账户
void destroy(Account *act)
{
	assert(act != NULL);
	free(act);
}
//取款
double withdraw(Account *act, double amount)
{
	assert(act != NULL);
	P(act->semid,0,1);
	double balance =act -> balance;
	if(amount < 0 || balance < amount )
	{
	     V(act->semid,0,1);
		return 0;
	}
	sleep(1);
	balance -=amount;
	act->balance = balance;
	V(act->semid,0,1);
	return amount;
}
//存款
double deposit(Account *act , double amount)
{
	assert(act != NULL);
	double balance = act->balance;
	P(act->semid,0,1);
	if(amount < 0)
	{
	V(act->semid,0,1);
		return 0;
	}
	sleep(1);
	balance += amount;
	act->balance = balance;
	V(act->semid,0,1);
	return amount;
}
//察看余额
double getBalance(Account *act)
{
	assert(act != NULL);
	double balance = act->balance;
	sleep(2);
	return balance;
}



