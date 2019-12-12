#include <stdio.h>
float average(int n,...)
{
	int *p=&n;
	int i = 1;
	int s = 0;
	for(i;i <= n;i++)
	{
		s+=*(p+i);
	}
	return s/n;
}
int main(void)
{
	float s= average(5,1,2,3,4,5);
	printf("s=%f\n",s);
	return 0;
}


