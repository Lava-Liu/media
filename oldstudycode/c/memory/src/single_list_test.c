#include "single_list.h"
#include <stdio.h>

int main(void)
{
	ElementType a = 10;
	ElementType b = 20;
	ElementType c = 30;
	ElementType d = 40;
	ElementType e = 50;
	ElementType f = 60;
	list *l = creat_list();
	push_front(l,&a);
	push_back(l,&b);
	push_back(l,&c);
	query(l);
	remove_back(l);
	insert_element(l,2,&f);
	printf("size=%d\n",size(l));
	query(l);
	destory_list(l);
	return 0;
}
