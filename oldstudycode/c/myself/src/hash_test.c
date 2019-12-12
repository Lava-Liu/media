#include "hash.h"
#include <stdio.h>

int main(void)
{
	printf("size=:%d\n",size());
	
	entable(5);
	entable(6);
	entable(7);
	entable(8);
	entable(9);
	printf("size=:%d\n",size());
	remove_element(5);
	printf("size=:%d\n",size());

	out_table();

}
