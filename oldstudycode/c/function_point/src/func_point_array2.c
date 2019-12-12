#include <stdio.h>
#include <stdlib.h>
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int div_me(int a,int b)
{
	return a/b;
}
//int (*pfun)(int ,int);
int (*array[4])(int ,int )={add,sub,mul,div_me};
int main(void)
{
	while(1)
	{
	printf("------------------------\n");
	printf("----1.add---------------\n");
	printf("----2.sub---------------\n");
	printf("----3.mul---------------\n");
	printf("----4.div---------------\n");
	printf("----5.quit--------------\n");
	printf("------------------------\n");
	printf("------------------------\n");
	int num1,num2;
	char c;
	int result = 0;
	printf("请输入number1：");
	scanf("%d",&num1);
	printf("请输入number2：");
	scanf("%d",&num2);
	getchar();
	printf("请输入你要做的计算操作：");
	scanf("%c",&c);
	switch(c)
	{
		case '1':
			result = array[0](num1,num2);
			break;
		case '2':
			result = array[1](num1,num2);
			break;
		case '3':
			result = array[2](num1,num2);
			break;
		case '4':
			result = array[3](num1,num2);
			break;
		case '5':
			printf("exit!\n");
			exit(1);
		default:
			printf("wrong !\n");
			break;

	}
	printf("result is: %d\n",result);
	getchar();
	}
	return 0;
}
