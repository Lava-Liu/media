#include "act_th.h"
#include "account.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <assert.h>


void *th_operation(void *arg)
{
	Operation *op=(Operation *)arg;
	double ret_amount=0;
	if(IS_WITHDRAW(op->type))
	{
		ret_amount=withdraw(op->act,op->amount);
		if(!ret_amount)
		{
			fprintf(stderr,"Operation not permitted!\n");
			pthread_exit((void *)-1);
		}
		printf("%s(%lx) withdraw %.2lf,balance: %.2lf\n",op->name,
				                                         pthread_self(),
														 ret_amount,
														 op->act->balance);
	}else
	if(IS_DEPOSIT(op->type))
	{
		ret_amount=deposit(op->act,op->amount);
		if(!ret_amount)
		{
			fprintf(stderr,"Operation not permitted!\n");
			pthread_exit((void *)-1);
		}
		printf("%s(%lx) deposit %.2lf,balance: %.2lf\n",op->name,
				                                         pthread_self(),
														 ret_amount,
														 op->act->balance);

	}else
	if(IS_GETBALANCE(op->type))
	{
		ret_amount=getBalance(op->act);
		if(!ret_amount)
		{
			fprintf(stderr,"Operation not permitted!\n");
			pthread_exit((void *)-1);
		}
		printf("%s(%lx) getbalance %.2lf,balance: %.2lf\n",op->name,
				                                         pthread_self(),
														 ret_amount,
														 op->act->balance);

	}else
	{
		fprintf(stderr,"Unknow operation type!\n");
		pthread_exit((void *)-1);
	}

}
pthread_t op_handler(Operation *op)
{
	assert(op != NULL);
	pthread_t th;
	if(pthread_create(&th,NULL,th_operation,(void *)op)!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		return (pthread_t)-1;
	}
	return th;

}




