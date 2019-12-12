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
void shell_sort(int a[],int n)
{
	int i;
	int j;
	int step =n;
	int temp;
	/*while(step>=1)
	{
		step=step/2;
		
		for(j=step;j<(n-step);j++)
		{
			if(a[j]>a[j+step])
			{
				temp=a[j+step];
				a[j+step]=a[j];
				a[j]=temp;
					

			}
			if(a[j]<a[j-step])
			{
				temp=a[j];
				a[j]=a[j-step];
				a[j-step]=temp;


			}
		}
		
		out(a,n);
		
			

	}


	

}*/
	while(step>0)
{
	step/=2;
	for(i=step;i<n;i++)
	{
		temp=a[i];
		for(j=i;j >= step; j-=step)
		{
			if(a[j-step]> temp)
				a[j]=a[j-step];
			    
			else break;
		}
		a[j]=temp;

	}
	
	out(a,n);
}
}
int main(void)
{
    int a[8]={2,11,3,132,89,77,22,76};
	int n =sizeof(a) / sizeof(int);
	out(a,n);
	shell_sort(a,n);
	out(a,n);
	return 0;
}
