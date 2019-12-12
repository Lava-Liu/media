#include "hash_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_LEN  5
list* creat_table()
{
		list *l[MAX_LEN];
		int i;
		for(i=0;i<MAX_LEN;i++)
		{
			l[i]=creat_list();
		}

return *l;

} 

int  entable(list *l,ElementType *e)
{
	if(l == NULL || e == 0) return 0;
	char i = *e % MAX_LEN;
	push_front(l+i*sizeof(list),e); 
	return 1;
}

	

query_table(list*l)
{
	int i;
	for(i=0;i<MAX_LEN;i++)
	{
		query(l+(char)i*sizeof(list));
	
	}
}

