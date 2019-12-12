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
	int (*(*pfun)[4])(int ,int );
	pfun = &array;
	int num1 =10;
	int num2 = 20;
	int result = (*(*pfun+0))(num1,num2);
	printf("%d\n",result);
	return 0;
}
