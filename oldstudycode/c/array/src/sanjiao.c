#include <stdio.h>
static int a[50][50];
int main(void)
{
	
	int i;
	int j;
	int b;
	
	
	printf("please input a number:");
	scanf("%d",&b);
    a[0][1]=1;
	printf("%d\n",a[0][1]);
    for(i=1;i<b;i++)
	{
		for(j=1;j<=i+1;j++)
		{
			
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}

    out(a,b);
	return 0;
}
void out(int *a,int data)
{
	int c;
	int d;
	for(c=0;c<=data;c++)
	{
		for(d=1;d<=c+1;d++)
		{
			printf("%d\t",*(a+c*50+d));
		}
		printf("\n");
	}

}
