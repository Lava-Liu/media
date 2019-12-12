#include <stdio.h>

int main(void)
{
	int a[5][5]={{1,2,3,4,5},{6,7,8,9,10}};
	int b[5]={1,2,3,4,5};
	printf("%d\n",*(*a));
	printf("%d\n",*((int *)a));
	printf("%d\n",*(*(a+1)));
	printf("%d\n",*((int *)(a+1)));
	printf("%d\n",*b);
	printf("%d\n",*b+1);
	printf("%d\n",*(b+1));

}
//int out(int *)
