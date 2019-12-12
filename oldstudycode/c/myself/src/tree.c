#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
tree* creat_tree(ElementType *e)
{
	if(e == 0) return NULL;
	tree *t=(tree *)malloc(sizeof(tree));
	if(t == NULL) return NULL;
	node *n=(node *)malloc(sizeof(node));
	if(n == NULL)return NULL;
	n->element=*e;
	t->root=n;
	return t;
}
static void destroy_node(node *n)
{
	if(n == NULL) return;
	destroy_node(n->next);
	destroy_node(n->last);
	free(n);
}
void destroy_tree(tree*t)
{	
	if(t == NULL) return ;
	destroy_node(t->root);
}
static node* add_n(node *n,ElementType *e)
{
	node *new = (node *)malloc(sizeof(node ));
	if(new == NULL ) return NULL;
	new->element = *e;
	if(n == NULL)
    {
		return new;
	}
	if(*e < n->element)
	{
		n -> last = add_n(n->last,e);
	}
	else if(*e > n->element)
	{
		n -> next = add_n(n->next,e);
	}
	return n;
	
}
int add_node(tree* t,ElementType *e)
{
	if(t == NULL || e == 0) return 0;
    t->root=add_n(t->root,e);
	return 1;
}
static node *get_min(node *n)
{
	if(n->last == NULL) return n;
	get_min(n->last);

}
static node * remove_n(node *n,ElementType *e)
{
	if(n == NULL) return NULL;
	if(*e < n->element)
	{
		n->last=remove_n(n->last,e);
	}else if(*e > n->element)
	{
		n->next=remove_n(n->next,e);
	}else
	{
		if(n->last && n->next)
		{
			node *temp = get_min(n->next);
			n->element = temp->element;
			n->next = remove_n(n->next,&temp->element);
			return n;
			
		}else
		{ node *temp = n;
			if(n->last)
			{
				n=n->last;
				free(n->last);
			}
			else if(n->next)
			{
				n=n->next;
				free(temp);
			}else
			{
				free(temp);
				n=NULL;
			}
		}
	}
	return n;
	

	
}
int remove_node(tree *t,ElementType *e)
{
	if(t == NULL || e == 0) return 0;
	t->root = remove_n(t->root,e);
	return 1;
	


}

static size_t size_node(node *n)
{
	if(n == NULL) return 0;
	return 1 + size_node(n->last) + size_node(n->next);
}
size_t size(tree*t)
{
	if(t == NULL ) return 0;
	return size_node(t->root);
}
static void mid_iten(node *n)
{
	if(n == NULL) return ;
	mid_iten(n->last);
	printf("%d, ",n->element);
	mid_iten(n->next);
}
void mid_iterator(tree *l)
{
	if(l == NULL) return;
	mid_iten(l->root);
	printf("\n");
}

