#include "double_list.h"
#include <stdio.h>


int main(void)
{
	
	ElementType a=10;
	ElementType b=20;
	ElementType c=30;
	ElementType d=40;
	ElementType e=50;
	ElementType f=60;
	ElementType g=70;
	ElementType h=80;
	ElementType i=90;
	list *stack=creat_stack();
	push(stack,&a);
	push(stack,&b);
	push(stack,&c);
	push(stack,&d);
	push(stack,&e);
	push(stack,&f);
	query(stack);
	printf("%d\n",pop(stack));
	printf("%d\n",pop(stack));
	printf("%d\n",pop(stack));
	query(stack);
	destroy_list(stack);
	return 0;
}
