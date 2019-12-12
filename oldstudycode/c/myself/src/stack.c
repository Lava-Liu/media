#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define LEN 100
static int a[LEN];
int counter=0;//用来保存栈中元素的个数
ElementType push(ElementType e)
{
	if(is_full())
		exit(1);
	a[counter++]= e;
	return e;
}
ElementType pop(void)
{
	if(is_empty())
		exit(1);
	return a[--counter];
}
ElementType top(void)
{
	return a[counter-1];
}
size_t size(void)
{
	return counter;
}
int is_empty(void)
{
	if(counter==0)
		return 1;
	return 0;

}
int is_full(void)
{
	if(counter == LEN)
		return 1;
	return 0;

}
void out_stack(int data)
{
	int i;
	for(i=0;i<data;i++)
	{
		printf("%d",pop());
	}

}


