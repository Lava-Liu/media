#include <stdio.h>
void out(int array[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d, ",array[i]);
	}
	printf("\n");
}
void select_sort(int a[],int n)
{
	int i;
	int j;
	int k;
	
	for(i=0;i<n;i++)
	{
		int min = i;		

		
		    for(k=i+1;k<n;k++)
			{
			if(a[k]<a[min])
			{
				min=k;
				
			}
			}
			if(min!=i)
			{
				int temp = a[min];
				a[min]=a[i];
				a[i]=temp;
			}
			
			
	}

	

}
int main(void)
{
    int a[6]={2,11,3,132,89,77};
	int n =sizeof(a) / sizeof(int);
	out(a,n);
	select_sort(a,n);
	out(a,n);
	return 0;
}
