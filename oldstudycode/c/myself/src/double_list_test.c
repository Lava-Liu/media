#include "double_list.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	ElementType a=10;
	ElementType b=20;
	ElementType c=30;
	ElementType d=40;
	ElementType e=50;
	ElementType f=60;
	list *l = creat_list();
	push_front(l,&a);
	push_back(l,&b);
	push_back(l,&c);
	push_back(l,&e);
	printf("size=%d\n",size(l));
	query(l);
	insert_element(l,&d,2);
	query(l);
	remove_front(l);
	query(l);
	remove_back(l);
	query(l);
	remove_index(l,2);
	query(l);

	printf("size=%d\n",size(l));
	printf("%d\n",*get(l,1));
	




	destroy_list(l);
	 return 0;
}
