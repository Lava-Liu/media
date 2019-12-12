#include <stdio.h>
void out(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d, ",a[i]);
	}
	printf("\n");
}
void swap(int *p,int *q)
{
	int temp = *p;
	*p=*q;
	*q=temp;
}
int media(int a[],int start,int end)
{
	int midm=(start+end)/2;
	if(a[start]>a[midm])
	{
		swap(&a[start],&a[midm]);
	}
	if(a[start]>a[end])
	{
		swap(&a[start],&a[end]);
	}
	if(a[midm]>a[end])
	{
		swap(&a[midm],&a[end]);
	}
	int mid = a[midm];
	swap(&a[midm],&a[end]);
	return mid;
}
void quick_sort(int a[],int start,int end)
{
	if(start >= end) return;
    int mid = media(a,start,end);
	int i=start-1;
	int j=end;
    while(1)
	{
		while(a[++i] < mid);
		while(a[--j] > mid);
		if(i > j)
			break;
        swap(&a[i],&a[j]);
	}
		swap(&a[i],&a[end]);
		quick_sort(a,start,i-1);
		quick_sort(a,i+1,end);
		
}
int main(void)
{
	int a[]={9,8,7,6,5,4,3,2,1};
	int n = sizeof(a)/sizeof(int);
	out(a,n);
	quick_sort(a,0,n-1);
	out(a,n);


	return 0;
}
