#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <pthread.h>
typedef struct
{
	long id;
	double balance;
	pthread_rwlock_t rwlock;
    int semid;


}Account;

//函数的申明
extern Account *init(long id,double balance);
void destroy(Account *act);
double withdraw(Account *act, double amount);
double deposit(Account *act , double amount);
double getBalance(Account *act);



#endif
