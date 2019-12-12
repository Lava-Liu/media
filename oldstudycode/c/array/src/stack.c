#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#define LEN 100
static ElementType stack[LEN];

size_t counter;//栈中当前元素的个数

/*
 * 往栈中放入一个元素，成功返回该元素
 */
ElementType push(ElementType e)
{
	if(is_full())
		exit(1);
	stack[counter++] = e;
    return e;
}
/*
 * 弹出栈顶元素返回弹出的元素
 */
ElementType pop(void)
{
	if(is_empty())
		exit(1);
	return stack[--counter];
}
//复制获取栈顶元素
ElementType top(void)
{
	if(is_empty())
		exit(1);
	return stack[counter-1];
}
//判断栈中元素的个数
size_t size(void)
{
	return counter;
}
//判断栈是否为空
int is_empty(void)
{
	if(counter==0)
		return 1;
	return 0;
}
//判断栈是否满
int is_full(void)
{
	if(counter==LEN)
		return 1;
	return 0;
}
ElementType out_stack(int data)
{
	int i;
	for(i=data-1;i>=0;i--)
	printf("%d",stack[i]);
	
 
}
