#include <stdio.h>
void out(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void insert_sort(int a[],int n)
{
	int i;
	int j;
	int temp;
	for(i=0;i<n;i++)
	{ 
		temp=a[i];
		for(j=i;j>0;j--)
		{
			if(a[j-1]<temp)
				a[j]=a[j-1];
			else
				break;
		}
		a[j]=temp;
	}
}
int main(void)
{
	int a[8]={21,43,432,346,54,7,67865,865};
	int n=sizeof(a)/sizeof(int);
	out(a,n);
	insert_sort(a,n);
	out(a,n);
	return 0;
}
