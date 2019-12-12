#include <stdio.h>
int factorial(int n)
{
	if(n==1) return 1;
	return n*factorial(n-1);

}
int main(void)
{
	int num;
    printf("Please input a number:");
	scanf("%d",&num);
	while(num <= 0)
	{
		printf("Wrong number!please input again:");
		scanf("%d",&num);
	}
	printf("%d\n",factorial(num));
	return 0;
}
