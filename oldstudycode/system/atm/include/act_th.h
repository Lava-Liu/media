#ifndef _ACT_TH_H_
#define _ACT_TH_H_
#include "account.h"
#include <pthread.h>


#define OP_WITHDRAW    1
#define OP_DEPOSIT     2
#define OP_GETBALANCE  3

#define IS_WITHDRAW(type) \
	((type) == OP_WITHDRAW)
#define IS_DEPOSIT(type) \
	((type) == OP_DEPOSIT)
#define IS_GETBALANCE(type) \
	((type) == OP_GETBALANCE)




typedef struct
{
	Account *act;//操作账户
	double amount;//操作额度
	char name[20];//操作用户
	int type;//操作类型
}Operation;


extern void *th_operation(void *arg);
extern pthread_t op_handler(Operation *op);



#endif
