#include <stdio.h>
int fun1(int a,int b)
{
	int max=1;
	int i=3;
	for(i;i<((a<b)?a:b);i++)
	{
		if( a%i == 0 && b%i == 0)
		{
			max = i;
		}
	}
	return max;
}
int fun2(int a,int b)
{
	int min=a;
	int j = (a>b)?a:b;
	while(1)
	{
		if( j%a == 0 && j%b == 0)
		{
			min = j;
			break;
		}
		j++;
	}
	return min;
}	
int main(void)
{
	int a;
	int b;
	printf("Please input  a number:");
	scanf("%d%d",&a,&b);
	
	
	printf("最大公约数为：%d最小公倍数为%d\n",fun1(a,b),fun2(a,b));
	return 0;
}
