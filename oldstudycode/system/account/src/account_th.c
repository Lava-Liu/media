#include "account.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

#define OP_GETBALANCE 0
#define OP_WITHDRAW   1
#define OP_DEPOSIT    2

#define IS_GETBALANCE(op_type) ((op_type) == OP_GETBALANCE)
#define IS_WITHDRAW(op_type) ((op_type) == OP_WITHDRAW)
#define IS_DEPOSIT(op_type) ((op_type) == OP_DEPOSIT)

typedef struct
{
	Account *account;
	char name[20];
	double amount;
	int op_type;
}Operation;

void *th_operation(void *arg)
{
	//还原
	Operation *op = (Operation *)arg;
	//解析操作
	if(IS_WITHDRAW(op->op_type))
	{//取款
		double ret_amt;
		ret_amt = withdraw(op->account,op->amount);
		if(ret_amt == 0)
		{
			fprintf(stderr,"operation exception!");
			pthread_exit((void *)-1);
		}
		printf("%s(%lx)  withdraw from account: %lu ,balance: %.2lf\n"
				,op->name,pthread_self(),op->account->id,
				op->account->balance);
	}else if(IS_DEPOSIT(op->op_type))
	{//存款
		double ret_amt;
		ret_amt = deposit(op->account,op->amount);
		if(ret_amt == 0)
		{
			fprintf(stderr,"operation exception!");
			pthread_exit((void *)-1);
		}
		printf("%s(%lx)  deposit from account: %lu ,balance: %.2lf\n"
				,op->name,pthread_self(),op->account->id,
				op->account->balance);

	}else if(IS_GETBALANCE(op->op_type))
	{//察看余额
		double ret_amt;
		ret_amt = getBalance(op->account);
		if(ret_amt == 0)
		{
			fprintf(stderr,"operation exception!");
			pthread_exit((void *)-1);
		}
		printf("%s(%lx)   from account: %lu ,balance: %.2lf\n"
				,op->name,pthread_self(),op->account->id,
				op->account->balance);

	}else
	{//unknow
		fprintf(stderr,"unknow operation!\n");
		pthread_exit((void *)-1);
		
	}
	pthread_exit((void *) 0);
}


int main(void)
{
	//创建账户
	Account *account = init(10086,10000.0);
	//zhangsan withdraw   1000
	Operation op1;
	op1.account = account;
	strcpy(op1.name,"zhangsan");
	op1.op_type = OP_WITHDRAW;
	op1.amount = 1000.0;
	pthread_t th1;
	if(pthread_create(&th1,NULL,th_operation,(void *)&op1)!=0)
	{
		fprintf(stderr,"th_create:  %s\n",strerror(errno));
		exit(1);
	}
	//lisi     deposit    1000
	Operation op2;
	op2.account = account;
	strcpy(op2.name,"lisi");
	op2.op_type = OP_DEPOSIT;
	op2.amount = 1000.0;
	pthread_t th2;
	if(pthread_create(&th2,NULL,th_operation,(void *)&op2)!=0)
	{
		fprintf(stderr,"th_create:  %s\n",strerror(errno));
		exit(1);
	}
	//wangwu   getBalance 0
	Operation op3;
	op3.account = account;
	strcpy(op3.name,"wangwu");
	op3.op_type = OP_GETBALANCE;
	pthread_t th3;
	if(pthread_create(&th3,NULL,th_operation,(void *)&op3)!=0)
	{
		fprintf(stderr,"th_create:  %s\n",strerror(errno));
		exit(1);
	}
	//zhangliu geiBalance 0
	Operation op4;
	op4.account = account;
	strcpy(op4.name,"zhangliu");
	op4.op_type = OP_GETBALANCE;
	pthread_t th4;
	if(pthread_create(&th4,NULL,th_operation,(void *)&op4)!=0)
	{
		fprintf(stderr,"th_create:  %s\n",strerror(errno));
		exit(1);
	}
	

	//销毁
	//pthread_cancel();
	sleep(10);
	double final = getBalance(account);
	printf("%lu %.2lf\n",account->id,final);
	destroy(account);

	return 0;
}
