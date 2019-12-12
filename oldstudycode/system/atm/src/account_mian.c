#include "act_th.h"
#include "account.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void)
{
	Account *act=init("10086",10000.0);
	Operation *op1=(Operation *)malloc(sizeof(Operation));
	strcpy(op1->name,"zhangsan");
	op1->type=OP_WITHDRAW;
	op1->amount=1000.0;
	op1->act=act;
	pthread_t th1;
    th1=op_handler(op1);
	printf("th: %lo create success!\n",th1);\

	//Operation *op2;
	Operation *op2=(Operation *)malloc(sizeof(Operation));
	strcpy(op2->name,"lisi");
	op2->type=OP_DEPOSIT;
	op2->amount=2000.0;
	op2->act=act;
	pthread_t th2;
    th2=op_handler(op2);
	printf("th: %lo create success!\n",th2);

	//Operation *op3;
	Operation *op3=(Operation *)malloc(sizeof(Operation));
	strcpy(op3->name,"wangwu");
	op3->type=OP_GETBALANCE;
	op3->act=act;
	pthread_t th3;
    th3=op_handler(op3);
	printf("th: %lo create success!\n",th3);
	
	//Operation *op4;
	Operation *op4=(Operation *)malloc(sizeof(Operation));
	strcpy(op4->name,"zhaoliu");
	op4->type=OP_GETBALANCE;
	op4->act=act;
	pthread_t th4;
    th4=op_handler(op4);
	printf("th: %lo create success!\n",th4);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);
	pthread_join(th4,NULL);
	printf("Now balance is ?,%.2lf\n",act->balance);
	destroy(act);
	free(op1);
	free(op2);
	free(op3);
	free(op4);
   return 0;
}
