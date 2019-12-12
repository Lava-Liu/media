#ifndef _HASH_LIST_H_
#define _HASH_LIST_H_
typedef int ElementType;
typedef unsigned int size_t;

typedef struct node
{
	struct node  *last;
	struct node  *next;
	ElementType element;
}node;
typedef struct list
{
	node head;
}list;

extern list *creat_list();
extern void destroy_list(list*l);
extern int push_front(list*l,ElementType *e);
extern int push_back(list*l,ElementType *e);
extern int insert_back(list*l,ElementType *e,int index);
extern int remove_front(list*l);
extern int remove_back(list*l);
extern int remove_index(list*l,int index);
extern size_t size(list*);
extern ElementType *get(list*,int index);
extern void query(list*);





extern list* creat_table();
extern int entable(list *,ElementType *e);
extern query_table(list*);

#endif
