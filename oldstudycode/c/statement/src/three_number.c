#include <stdio.h>
#define N 10
int main(void)
{
	int a[N];
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",a);
		if(a[i]=='\n')
			break;
	}
	out_three_number(a);
}
int out_three_number( int a[] )
{
	int max=a[0];
	int j,k,f;
	int d;
	for(k=1;k<=N;k++){
	for(j=1;j<=N;j++)
	{
		if(a[j]>=max)
		{
			d=a[j-1];
			a[j-1]=a[j];
			a[j]=d;
			
		}
	}
	}
	for(f=0;f<=N;f++)
	{
		printf("%d",a[f]);
	}
}
