#include <stdio.h>
void swap_1(int a,int b)
{
	int temp = a;
	a =b;
	b = temp;
}
void swap_2(int *p,int *q)
{
	int temp = *p;
	*p=*q;
	*q=temp;
}
int main(void)
{
	int a=1;
	int b=2;
	swap_2(&a,&b);
	printf("a=%d,b=%d\n",a,b);
	//swap_2((i1<F3>nt *)a,(int *)b);
	//printf("a=%d,b=%d\n",a,b);

	return 0;
}
