#include "hash_list.h"
#include <stdio.h>

int main(void)
{
	ElementType a = 10;
	ElementType b = 21;
	ElementType c = 32;
	ElementType d = 43;
	ElementType e = 54;
	list *l=creat_table();
	entable(l,&a);
	entable(l,&b);
	entable(l,&c);
	entable(l,&d);
	entable(l,&e);
	query_table(l);
		return 0;
}
