#include <stdio.h>
#include "stdio.h"
int main(void)
{
	char n;
	int i;
	for(;;)
	{
		if(n == '\n')
			break;
		scanf("%c",&n);
		if((n>='A') && (n<='Z') )
		{
			i='A'-'a';
			n=n-i;
			
		}

		push(n);
		
	}
	while(size()!=0)
	{
		printf("%c ",pop());
	}
	printf("\n");
return 0;

}
