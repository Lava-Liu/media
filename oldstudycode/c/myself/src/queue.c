#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#define LEN 5
ElementType a[LEN];
int counter=0;
int head;
int tail;
ElementType enqueue(ElementType e)
{
	if(is_full())
		exit(1);
	a[tail++] = e;
	counter ++;
	tail = tail % LEN;
	return e;



}
ElementType dequeue(void)
{
	if(is_empty())
		exit(1);
	ElementType temp;
	  temp=a[head++];
	  head = head % LEN;
	  counter--;
	  return temp;
			
}
ElementType cpqueue(void)
{
	return a[head];
}
size_t size(void)
{
	return counter;

}
int is_empty(void)
{
	if(counter==0)
		return 1;
	return 0;
}
int is_full(void)
{
	if(counter==LEN)
		return 1;
	return 0;
}
void out_queue(void)
{
	int i;
	for(i=0;i<LEN;i++)



	printf("%d\n",dequeue());

}



