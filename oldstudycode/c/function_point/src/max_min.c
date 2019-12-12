#include <stdio.h>


int a[]= {22,534,6754,465,321,423,32};
int max_comp(int i,int j)
{
	return i-j;
}
int min_comp(int i,int j)
{
	return  j-i;
}
int max_min(int *a,int n,int(*comp)(int ,int))
{
	int m=a[0];
	int i=1;
	for(i;i<n;i++)
	
	{
		if(comp(a[i],m)>0)
			m=a[i];
	}
	return m;
}
int max(int *a,int n)
{
	int m=a[0];
	int i;
	for(i=1;i<n;i++)
	
	{
		if(a[i]>m)
			m=a[i];
	}
	return m;
}
int min(int *a,int n)
{
	int m=a[0];
	int i=1;
	for(i=1;i<n;i++)
	
	{
		if(a[i]<m)
		m=a[i];
	}
	return m;
}
int main(void )
{
	int n=sizeof(a)/sizeof(int );
	int m=max(a,n);
	printf("%d\n",m);
	int mi=min(a,n);
	printf("%d\n",mi);
	 m = max_min(a,n,max_comp);
	printf("max=%d\n",m);
	 m = max_min(a,n,min_comp);
	printf("max=%d\n",m);
	
	return 0;
}
