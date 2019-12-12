#include <stdio.h>
void out(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",*(a+i));
	}
	printf("\n");
}
void shell_sort(int a[],int n)
{
	int i;
	int j;
	int step=n;
	int temp;
	while(step>0)
	{
		step/=2;
		for(i=step;i<n;i++)
		{

		temp=a[i];
		for(j=i;j >=step ;j-=step)
		{
			if(a[j-step]>temp)
				a[j]=a[j-step];
			else
				break;

		}
		a[j]=temp;

}
}
}
void two_find(int data,int n,int a[])
{
	int i=0;
	int b=(n-i);
	for(b;b>1;b=(n-i))
	{
	if(data <= a[i+(b/2)])
	
		n=i+b/2;
	
	else
		i=i+b/2;

	}
	if(a[n]==data)
	printf("%d\n",n);
	if(a[i]==data)
	printf("%d\n",i);

}
int main(void)
{
	int a[9]={222,45,76,766,44,53,4543,7567,9};
	int n=sizeof(a)/sizeof(int);
	int b;
	out(a,n);
	shell_sort(a,n);
	out(a,n);
	printf("Please input a number:");
	scanf("%d",&b);
	two_find(b,n,a);
}
