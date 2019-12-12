#include <stdio.h>

int main(void)
{
	int a;
	int i=0;
	int remained =0;
	static int bits[32];
	printf("Please input a number:");
	scanf("%d",&a);
	for(;;) 
	{
		if(a == 0) break;
		remained = a % 2;
		a = a /2;
		bits[i++]=remained;
	}

	for(i=31;i>=0;i--)
	{
		printf("%d",bits[i]);

	}
	printf("\n");
	
}
