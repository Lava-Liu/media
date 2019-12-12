#ifndef _LIST_H_
#define _LIST_H_
typedef int ElementType;
typedef unsigned int size_t;
typedef struct node
{
	ElementType element;
	struct node *next;
}node;

typedef struct list
{
	node head;
}list;

extern list* creat_list();
extern void destory_list(list*l);
extern int push_front(list*l,ElementType *e);
extern int push_back(list*l,ElementType *e);
extern int  insert_element(list *l,int index,ElementType *e);
extern int remove_front(list*l);
extern int remove_back(list*l);
extern int remove_element(list*l,int index);
extern size_t size(list *);
extern ElementType* get(list *l,int index);
extern void query(list *l);



#endif
