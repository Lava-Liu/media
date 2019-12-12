#include "hash.h"
#include <stdio.h>

int main(void)
{
	entable(15);
	entable(21);
	entable(22);
	entable(23);
	entable(24);
	remove_element(24);
	out_table();
	if(checktable(23)==1)
	{
		printf("exist!\n");
	}
	return 0;
}
