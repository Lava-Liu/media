#include "queue.h"
#include <stdio.h>

int main(void)
{
	enqueue(1);
	printf("%d\n",cpqueue());
	printf("%d\n",dequeue());
	printf("%d\n",size());
    
	enqueue(2);
	printf("%d\n",cpqueue());
	
	enqueue(3);
	printf("%d\n",cpqueue());
	
	enqueue(4);
	printf("%d\n",cpqueue());
	printf("%d\n",dequeue());
	enqueue(5);
	printf("%d\n",cpqueue());
	printf("%d\n",dequeue());
	enqueue(6);
	printf("%d\n",cpqueue());
	printf("%d\n",dequeue());
    out_queue();
}
