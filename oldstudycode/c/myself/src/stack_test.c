#include "stack.h"
#include <stdio.h>

int main(void)
{
	push(1);
	push(2);
	push(3);
	push(4);
	
	printf("aize=%d\n",size());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	
	printf("size=%d\n",size());
}
