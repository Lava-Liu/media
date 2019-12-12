#include "bin.h"
#include <stdio.h>

void out_bin(int data)
{
	int n = 31;
	int r;
	while(n>=0)
	{
		r = (data >> n) & 1;
		printf("%d",r);

		n--;

	}
	printf("\n");
}


void out_bin_any(void *p ,int bytes )
{
	int n = bytes - 1;
	while(n>=0)
	{
		char *pa = (char*)p;
		pa +=n;
		char c = *pa;
		out_char(c);
		n--;
	}
	printf("\n");
	
}

void out_char(char data)
{
	int n = 7;
	int r;
	//while(n>=0)
	for(n=7;n>=0;n--)
	{
		r = (data >> n) & 1;
		printf("%d",r);
		//n--;
	}
	

}
void set_bit(int *p,int n)
{
	*p |=(1 << n-1);
}
void clr_bit(int *p,int n)
{
	int d = ~(1 << n-1);
		*p&=d;
}
void stack_out(int data)
{
	int n=0;
	while(n<32)
	{
		push((data & 1));
		data >> 1;
		n++;
	}
	while(size()!=0)
	{
		printf("%d",pop());
	}
	return 0;
}


