#include "single_list.h"
#include <stdio.h>
#include  <stdlib.h>
#include <malloc.h>

list* creat_list()
{
	list *l = (list*)malloc(sizeof(list));
	if(l == NULL) return NULL;
	l->head.element = 0;
	l->head.next = NULL;
	return l;
}
static void destory_node(node *n)
{
	if(n->next == NULL) return;
	destory_node(n->next);
	free(n);
	/*node *temp = NULL;
	while(n->nenxt!=NULL)
	{
		temp = n;
		n = n-next;
		free(temp);
	}*/
}
void destory_list(list*l)
{
	if(l == NULL) return;
	destory_node(l->head.next);
	free(l);
}
int push_front(list*l,ElementType *e)
{
	if(l == NULL || e == NULL ) return 0;
		node *new = (node*)malloc(sizeof(node));
	if(new == NULL) return 0;
		new->element= *e;
		new->next = NULL;

		new->next = l->head.next;
		l->head.next = new;
		l->head.element++;
		return 1;
}
static node* tail(node*n)
{	
	if(n->next == NULL) return n;
	tail(n->next);
}
int push_back(list*l,ElementType *e)
{
	if(l == NULL || e == NULL ) return 0;
	node *end = tail(&l->head);
		node *new = (node*)malloc(sizeof(node));
	if(new == NULL) return 0;
		new->element= *e;
		new->next = NULL;
		end->next = new;

		l->head.element++;

		return 1;
	
}
static node* previous(node *n,int index)
{
	if(n == NULL) return ;
	if(index == 0) return n;
	previous(n->next,index-1);

}
int  insert_element(list *l,int index,ElementType *e)
{
	if(l == NULL || e == NULL ) return 0;
	node *pre_node = previous(&l->head,index-1);
		node *new = (node*)malloc(sizeof(node));
	if(new == NULL) return 0;
		new->element= *e;
		new->next = NULL;
		new->next = pre_node->next;
		pre_node->next = new;
		l->head.element++;
		
		return 1;

}
int remove_front(list*l)
{
	if(l == NULL) return 0;
   node *second = (l->head.next)->next;
	free(l->head.next);
	l->head.next=second;
	l->head.element--;
	return 1;	
}
int remove_back(list*l)
{
	if(l == NULL) return 0;
	node*n =previous(&l->head,l->head.element-1);
	free(n->next);
	n->next=NULL;
	l->head.element--;
	return 1;
}
int remove_element(list*l,int index)
{
	if(l == NULL)return 0;
	node *n =previous(&l->head,index-1);
	node *next =previous(&l->head,index+1);
	free(n->next);
	
	n->next=next;
	l->head.element--;
	return 1;
	
}
size_t size(list*l)
{
	return l->head.element;
}
ElementType* get(list *l,int index)
{
	if(l == NULL ) return 0;
	node *n = previous(&l->head,index);
	return &(n->element);
}
void query(list *l)
{
	if(l == NULL ) return ;
	node* n = &l->head;
	while(n->next != NULL)
	{
		n = n->next;
		printf("%d, ",n->element);
	}
	printf("   counter:%d\n-------------------------------\n",l->head.element);
}



