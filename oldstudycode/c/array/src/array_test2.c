#include <stdio.h>

int main(void)
{
	int a[5]= {1,3,22,21,30};
	printf("sizeof(a)=%d\n",sizeof(a));
	printf("sizeof(a[0])=%d\n",sizeof(a[0]));
	printf("sizeof(a[5])=%d\n",sizeof(a[5]));
	printf("sizeof(&a[0])=%d\n",sizeof(&a[0]));
	printf("sizeof(&a)=%d\n",sizeof(&a));

	printf("(&a[0])=%p\n",&a[0]);
	printf("(&a)=%p\n",&a);
	printf("a=%p\n",a);

	return 0;
}
