#include <stdio.h>

int main(void)
{
	int i = 1;
	for(i; i<=10 ; i++)
	{
		if((i&1)==0)
		{
			continue;
			//exit(1);
			//return 0;
			//goto label;
		}else
		printf("%d\n",i);
		
	}
//label:
	//printf("finish!\n");
	return 0;
}
