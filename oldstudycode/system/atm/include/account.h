#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <pthread.h>
typedef struct
{
	char id[10];
	double balance;
	pthread_rwlock_t lock;
}Account;
//初始化账户
extern Account *init(char *id,double amount);
//销毁账户
extern void destroy(Account *act);
//取款
extern double withdraw(Account *act,double amount);
//存款
extern double deposit(Account *act,double amount);
//查询余额
extern double getBalance(Account *act);

#endif
