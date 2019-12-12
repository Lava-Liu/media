#include <stdio.h>
void out_array(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);

}
int main(void)
{
	int a[]={1,2,3,45,4};
	int i;
	int n=sizeof(a)/sizeof(int);
	for(i=0;i<n;i++)
	{
		printf("%d\t",*(a+i));
	}
	printf("--------------------------\n");
	out_array(a,n);
}
