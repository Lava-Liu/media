#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	ElementType a = 10;
	ElementType b = 20;
	ElementType c = 30;
	ElementType d = 40;
	ElementType e = 50;
	ElementType f = 60;
	ElementType g = 70;
	tree * t = creat_tree(&d);
	add_node(t,&a);
	add_node(t,&b);
	add_node(t,&c);
	add_node(t,&e);
	add_node(t,&f);
	add_node(t,&g);
	mid_iterator(t);
	printf("%d\n",size(t));
	remove_node(t,&a);
	remove_node(t,&b);
	remove_node(t,&c);
	remove_node(t,&d);
	mid_iterator(t);
	printf("%d\n",size(t));
	destroy_tree(t);



	return 0;
}
