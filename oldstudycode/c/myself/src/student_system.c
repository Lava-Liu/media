#include "student_system.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
list* creat_list()
{
	list* l=(list*)malloc(sizeof(list));
	if( l == NULL ) return NULL;
	l->head.code=0;
	l->head.age=0;
	l->head.score=0.0;
	l->head.next=NULL;
	l->head.before=NULL;
	return l;
}
static void destroy_node(node*n)
{
	if(n == NULL) return;
	destroy_node(n->next);
	free(n->next);
}
void destroy_list(list*l)
{
	if(l == NULL) return ;
	destroy_node(&l->head);
	free(l);
	l=NULL;
}
int push_front(list*l,int *code,int *age,char *name,double *score)
{
	if(l == NULL) return 0;
	node *new = (node *)malloc(sizeof(node));
	node *head = &l->head;
	if(new == NULL) return 0;
	new->code=*code;
	new->score=*score;
    new->age=*age;
	new->name=(char *)malloc(20);
	strcpy(new->name,name);
	if(head->next=NULL)
	{
		new->before=head;
		head->next=new;
		l->head.code++;
		return 1;
	}
	new->before=head;
	head->next->before=new;
	new->next=head->next;
	l->head.code++;
	return 1;

}
static node *back_n(node *n)
{
	if(n->next==NULL) return n;
	back_n(n->next);
}
int push_back(list*l,int *code,int *age,char *name,double *score)
{
	if(l == NULL) return 0;
	node *new = (node *)malloc(sizeof(node));
	if(new == NULL) return 0;
	new->code=*code;
	new->score=*score;
	new->name=(char *)malloc(20);
	strcpy(new->name,name);
    new->age=*age;
	node *insert=back_n(&l->head);
	new->before=insert;
	insert->next=new;
	l->head.code++;
	return 1;
}
static node *previous(node *n,int index)
{
	if(n = NULL) return 0;
	if(index == 0) return n;
	previous(n->next,index-1);


}
int push_index(list*l,int *code,int *age,char *name,double *score,int index)
{
	if(l == NULL) return 0;
	node *new = (node *)malloc(sizeof(node));
	if(new == NULL) return 0;
	new->code=*code;
	new->name=(char *)malloc(20);
	strcpy(new->name,name);
	new->score=*score;
    new->age=*age;
	node *insert=previous(&l->head,index-1);
	node *insert2=previous(&l->head,index);
	insert->next=new;
	new->next=insert2;
	new->before=insert;
	insert2->before=new;
	l->head.code++;
	return 1;
	
	
}
int remove_front(list*l)
{
	if(l == NULL) return 0;
	node *second=previous(&l->head,2);
	free(l->head.next);
	l->head.next=second;
	second->before=&l->head;
	l->head.code--;
	return 1;
}
int remove_back(list*l)
{
	if(l == NULL) return 0;
	node *back=previous(&l->head,l->head.code-1);
	free(back->next);
	back->next=NULL;
	l->head.code--;
	return 1;
}
int remove_index(list*l,int index)
{
	if(l == NULL) return 0;
	node *index1=previous(&l->head,index-1);
	node *index2=previous(&l->head,index+1);
	free(index1->next);
	index1->next=index2;
	index2->before=index1;
	l->head.code--;
	return 1;
}
unsigned int size(list*l)
{
	return l->head.code;
}
static void query_node(node *n)
{
	if(n == NULL) return;

	
	query_node(n->next);
	printf("%d号  学生: %s 的年龄为：%d 成绩为：%lf \n",n->code,n->name,n->age,n->score);
}
void query(list*l)
{
	if(l==NULL) return ;
	node * head_n=&l->head;

	query_node(head_n->next);
}
static void data_n(node *n)
{
   FILE *fp = fopen("data.txt","wb");
   
   while(n->next!=NULL)
   {
		n=n->next;
		
		
	    fwrite(n,sizeof(node),1,fp);
		char *name_n = (char *)malloc(20);
		strcpy(name_n,n->name);
		fwrite(name_n,20,1,fp);
		
		
   }
}
int data(list*l)
{
	if(l == NULL) return 0;
	data_n(&l->head);
	return 1;
}






















