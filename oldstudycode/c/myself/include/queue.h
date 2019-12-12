#ifndef _QUEUE_H_
#define _QUEUE_H_
typedef int ElementType;
typedef unsigned int size_t;

ElementType enqueue(ElementType);
ElementType dequeue(void);
ElementType cpqueue(void);
size_t size(void);
int is_empty(void);
int is_full(void);
void out_queue(void);



#endif
