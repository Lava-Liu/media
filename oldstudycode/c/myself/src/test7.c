#include <stdio.h>

int main(void)
{
	int a[4]={1,2,3,4,5};
	int b[4][4]={1,2,3,4,5,6,7,8};
	printf("a;%p\n",a);
	printf("a+1;%p\n",a+1);
	printf("&a;%p\n",&a);
	printf("&a+1;%p\n",&a+1);
	printf("*a;%d\n",*a);
	printf("*a+1;%d\n",*a+1);
	printf("--------------------------\n");
	printf("b;%p\n",b);
	printf("b+1;%p\n",b+1);
	printf("&b;%p\n",*(&b));
	printf("&b+1;%p\n",*(b+1));
	printf("*b;%d\n",*(int *)b);
	printf("*b+1;%d\n",*(int *)(b+1));

	return 0;
}
