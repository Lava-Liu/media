#ifndef _TREE_H_
#define _TREE_H_
typedef int ElementType;
typedef unsigned int size_t;

typedef struct node
{
	ElementType element;
	struct node *next;
	struct node *last;
}node;
typedef struct tree
{
	node *root;
}tree;

extern tree* creat_tree(ElementType *e);
extern void destroy_tree(tree*t);
extern int  add_node(tree* t,ElementType *e);
extern int remove_node(tree *t,ElementType *e);
extern size_t size(tree*);
extern void mid_iterator(tree*);


#endif 
