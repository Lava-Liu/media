#include <stdio.h>
#include "stack.h"
int main(void)
{
	push(19);
	push(223);
	push(11);
	push(12);
	push(6);
	printf("size: %d\n",size());
    printf("top: %d\n",top());
	printf("pop: %d\n",pop());
	printf("top: %d\n",top());
	printf("pop: %d\n",pop());
	printf("top: %d\n",top());
	printf("pop: %d\n",pop());
	printf("top: %d\n",top());
	printf("pop: %d\n",pop());
	printf("top: %d\n",top());
	printf("pop: %d\n",pop());
	printf("size:%d\n",size());
return 0;
}
