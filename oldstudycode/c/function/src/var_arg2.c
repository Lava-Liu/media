#include <stdio.h>
float average(int n,...)
{
	char *p=(char *)&n;
	int i = 1;
	double s = 0;
	char *q = p+sizeof(int);
	for(i;i <= n;i++)
	{
		s+=*((double *)(q+(i-1)*sizeof(double)));
	}
	*p=0;
	return s/n;
}
int main(void)
{


	double s= average(5,1.0,2.0,3.0,4.0,5.5);
	printf("s=%lf\n",s);
	return 0;
}


