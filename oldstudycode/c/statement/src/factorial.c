#include <stdio.h>
#include <limits.h>



int main(void)
{
	int i,j;
	int sum =1;
	printf("Please input a number:");
	scanf("%d",&i);
	for(j=1;j<=i;j++ )
	{
		sum=sum*j;


	}
	if(sum<0)
	{
		printf("error!\n");
		return 0;
	}
	printf("the factorial of the number is :%d\n",sum);

return 0;

}
