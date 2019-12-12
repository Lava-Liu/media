#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int element;
	struct node *next;
}node;

node* creat_list()
{
	node *root = (node*)malloc(sizeof(node));
	if( root == NULL) return NULL;
	root->element = 0;
	root->next=NULL;
	return root;
}
void destroy(node *n)
{
	if(n->next==NULL) return;
	destroy(n->next);
	free(n);
}
static node*in_n(node *n,int element)
{
    if(n->next == NULL) return n;
	if(n->next->element > element) return n;
	in_n(n->next,element);
}
int insert_node(node *n,int element)
{
	if(n == NULL ) return 0;
	node* new = (node *)malloc(sizeof(node));
    if(new == NULL) return 0;
	new->element = element;
	if(n->next==NULL)
	{
		n->next=new;
		return 1;
	}
	node *in = in_n(n,element);
	new->next=in->next;
	in->next = new;
	n->element++;
	return 1;
		   
}
void display(node *n)
{
	int i;
	
	for(i=0;n->next!=NULL;i++)
	{
		n=n->next;
		printf("%d, ",n->element);
	}
	printf("\n");
	
}	
int main(void)
{
	node *l=creat_list();
	insert_node(l,3);
	insert_node(l,5);
	insert_node(l,2);
	insert_node(l,1);
	display(l);
	destroy(l);
	return 0;
}









