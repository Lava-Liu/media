#include <stdio.h>

int int_max()
{
	int d =1;
	while(1)
	{
		if((d +1)<0)
		{
			break;
		}else
		{
			d++;
		}
	}
	return ++d;
}
int  main(void)
{
	int counter =0;
	for(;;)
	{
		printf("%d\n",counter);
		counter++;
		sleep(1);
		
	}



}
