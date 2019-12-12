#include "double_list.h"
#include <stdio.h>
list*  creat_stack()
{
	return creat_list();
}
ElementType push(list *l,ElementType *e)
{
	push_front(l,e);
	return 1;
}
ElementType pop(list *l)
{
	ElementType e=*get(l,1);
	remove_front(l);
	return e;
}
