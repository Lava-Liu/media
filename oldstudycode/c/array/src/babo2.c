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
void bubble_sort(int array[],int n)
{
	int x;
	int i;
	int j;
	int flag;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			flag = 0;
				
		   if((array[j]>array[j+1]))
		   { x=array[j+1];
		   array[j+1]=array[j];
		   array[j]=x;
		   flag =1;
		   }
		}
		if(flag == 0)
			break;
		out(array,n);
		

	}

}
int main(void)
{
    int a[6]={2,11,3,132,89,77};
	int n =sizeof(a) / sizeof(int);
	out(a,n);
	bubble_sort(a,n);
	out(a,n);
	return 0;
}
