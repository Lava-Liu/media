#ifndef _STACK_H_
#define _STACK_H_
typedef int ElementType;
typedef unsigned int size_t;

ElementType push(ElementType);
ElementType pop(void);
ElementType top(void);
size_t size(void);
int is_empty(void);
int is_full(void);
void out_stack(int);



#endif
