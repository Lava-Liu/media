#include "queue.h"
#include <stdio.h>

int main(void)
{
	enqueue(1);
	enqueue(22);
	enqueue(66);
	enqueue(77);
	printf("%d\n",size());
	
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());

return 0;
}
