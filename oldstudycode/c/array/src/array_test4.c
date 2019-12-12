#include <stdio.h>
int main(void)
{
	int a[3][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int b[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int c[][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    out(a);
	out(b);
	out(c);
	printf("a:  %p\n",a);
	printf("&a:  %p\n",&a);
	printf("&a[0][0]:  %p\n",&a[0][0]);
	printf("a+1:  %p\n",a+1);
	printf("&a:  %p\n",&a+1);
	printf("&a[0][0]:  %p\n",&a[0][0]+1);

	return 0;
}
void out(int *a)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",*((int *)(a+i)+j));
		}
		printf("\n");
	}
}

