#ifndef _STUDENT_SISTEM_H
#define _STUDENT_SISTEM_H
typedef struct node
{
	int code;
	char *name;
	int age;
	double score;
	struct node *next;
	struct node *before;
}node;
typedef struct list
{
	node head;
}list;
extern list* creat_list();
extern void destroy_list(list*l);
extern int push_front(list*l,int *code,int *age,char *name,double *score);
extern int push_back(list*l,int *code,int *age,char *name,double *score);
extern int push_index(list*l,int *code,int *age,char *name,double *score,int index);
extern int remove_front(list*l);
extern int remove_back(list*l);
extern int remove_index(list*l,int index);
extern unsigned int size(list*l);
extern void query(list*l);
extern int  data(list*l);






















#endif
