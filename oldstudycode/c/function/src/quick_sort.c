#include <stdio.h>
void out(int array[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("%d, ",array[i]);
	}
	printf("\n");
}
void swap(int *p,int *q)
{
	int temp=*p;
	*p=*q;
	*q=temp;
}
int media(int a[],int start ,int end)
{
	int center = (start +end)/2;
	if(a[start] > a[center])
		 swap(&a[start],&a[center]);
	if(a[center]> a[end])
		swap(&a[center],&a[end]);
	if(a[start]>a[center])
		swap(&a[start],&a[center]);
	//out(a,7);
	int pivot = a[center];
	swap(&a[center],&a[end]);
	return pivot;
}
void quick_sort(int a[],int start,int end)
{
	if(start >= end ) return;
	int pivot = media(a,start,end);
	int i = start-1;
	int j = end;
	while(1)
	{
		while(a[++i] < pivot);
		while(a[--j] > pivot);
		if(i>j) break;
		swap(&a[i],&a[j]);
	}
	swap(&a[i],&a[end]);
	quick_sort(a,start,i-1);
	quick_sort(a,i+1,end);

}
int main(void)
{
	int a[]={9,8,7,6,5,4,3,2};
	int n = sizeof(a)/sizeof(int);
	out(a,n);
	quick_sort(a,0,n-1);
	out(a,n);
	return 0;
}
