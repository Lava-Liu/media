#include <stdio.h>

int fun2(int i,int j)
{
	int k= i+j;
	return k;
}
int fun1(int a,int b)
{
	int c=a;
	int d=b;
	fun2(c,d);
	
	return c+d;
}
int main(void)
{
	fun1(5,4);
	printf("hello world\n");
	return 0;
}
