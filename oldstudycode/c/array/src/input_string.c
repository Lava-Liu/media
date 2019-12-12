#include <stdio.h>

int main(void)
{
	char str[5];
	int i;
	for(i=0;i<sizeof(str)/sizeof(char);i++)
	{
	scanf("%c",&str[i]);
	int c;

	while((c= getchar()) !='\n');
	   continue;
	}
	for(i=0;i<5;i++)
	{
		printf("%d=%c ",i,str[i]);
	}
	printf("\n");
	return 0;
}
