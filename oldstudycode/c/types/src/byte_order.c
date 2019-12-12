#include <stdio.h>


int main(void)
{
	short int a =0x0102;
	short int* pa = &a;
	char *p = (char*)pa;
	if(*p==0x01 && *(p+1)==0x02)
	{
	printf("big edian\n");
	
	}else if(*p == 0x02 && *(p+1) == 0x01)
	{
	printf("litter eduan\n");

	}
	else
	{
	printf("erro!\n");
	}




return 0;
}
