#include <stdio.h>

int main(void)
{
	int a = 10;
	int* pa = &a;
	printf("a value =: %d\n",a);
    printf("a local =:0x%x\n",&a);
	printf("pa value =: %p\n",pa);
	printf("pa local =:0x%x\n",&pa);	
	printf("*pa local =:%d\n",*pa);

return 0;	








}
