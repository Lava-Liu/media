#include <stdio.h>

int main(void)
{
	char a[10];
	a[0]=getchar();
	a[1]=getchar();
	printf("%c\t",a[0]);
	printf("%c\t",a[1]);


	return 0;
}
