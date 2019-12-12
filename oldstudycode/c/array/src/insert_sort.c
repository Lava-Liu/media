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
void insert_sort(int a[],int n)
{
	int i;
	int j;
	for(i=1;i<n;i++)
	{
			int temp = a[i];

		for(j=i;j > 0;j--)
		{
			if(a[j-1]>temp)
			{
				a[j]=a[j-1];
				
			}
			else
				break;

		}
		a[j] = temp;
		out(a,n);
	}

	

}
int main(void)
{
    int a[6]={2,11,3,132,89,77};
	int n =sizeof(a) / sizeof(int);
	out(a,n);
	insert_sort(a,n);
	out(a,n);
	return 0;
}
