#include <stdio.h>

int main(void)
{
	int i=0;
	for(;;)
	{
		if((i-1)>0)
		{
			break;
		}
		else
		{
			i--;
		}
	}
	printf("%d\n",i);
	return 0;



}
