#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(void)
{
	ElementType a= 10;
	ElementType b= 20;
	ElementType c= 30;
	ElementType d= 40;
	ElementType e= 50;
	ElementType f= 60;
	ElementType g= 70;
	
	vector* v = creat_vector();
	push_front(v,&a);
	push_back(v,&b);
	push_back(v,&c);
	push_back(v,&d);
	push_back(v,&e);
	push_back(v,&f);
	push_back(v,&g);
	pop_back(v);
	pop_back(v);
	printf("size: %d\n",size(v));
	query(v);
	destory_vector(v);
	return 0;
}

