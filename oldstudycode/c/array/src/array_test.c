#include <stdio.h>

int main(void)
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i=0;
	for(i=0;i<10;i++)
		printf("a[%d]=%d\t",i,a[i]);

    printf("\n");
	printf("sizeof(a):%d\n",sizeof(a));
	int b[]={1,2,3,4,77};
	int size = sizeof(b)/sizeof(int);
	printf("number=:%d\n",size);

	int c[10];
	c[0] = 1;
	for(i=0;i<10;i++)
		c[i] = 0;
	
	
	return 0;
}
