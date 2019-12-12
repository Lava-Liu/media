#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <pthread.h>
typedef struct Account
{
	long ID;
	double balance;
	char name[20];
	pthread_rwlock_t rwlock;


}Account;

extern Account *init(long id,double balance,char *name);
extern void destroy_account(Account *act);
extern int withdraw(Account *act,double amount);
extern int deposit(Account *act,double amount);
extern double  getbalance(Account *act);






#endif
