#include "term.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
static member term[MAX_LEN];
size_t counter=0;

int add_member(member*m)
{
	if(counter < MAX_LEN)
	{
		term[counter++]= *m;
		return 1;
	}return 0;

}
int delete_member(int code)
{
	member *m = get(code);
	
	while(m<term+counter-1)
	{
		*m=*(m+1);
		m++;
		
	}
	return 1;
	return 0;
}
member* get(int code)
{
	int i;
	for(i=0;i<counter;i++)
	{
		if(term[i].person.t.code == code)
			return &term[i];
		return 0;

	}
}
static void teacher_query(member* m)
{
	printf("code=%d\nname=%s\nage=%d\nsalary=%lf\n",m->person.t.code,m->person.t.name,m->person.t.age,m->person.t.salary);

}
static void student_query(member* m)
{
	printf("code=%d\nname=%s\nage=%d\n",m->person.s.code,m->person.s.name,m->person.s.age);
	
}
void query()
{
	int i;
	for(i=0;i<counter;i++)
	{
		if(term[i].id==TEACHER)
		{
			teacher_query(&term[i]);
		}
		if(term[i].id==STUDENT)
		{
			student_query(&term[i]);
		}
	}
}
void out(int code)
{
	member* m=get(code);
		if(m->id==TEACHER)
		{
			teacher_query(m);
		}
		if(m->id==STUDENT)
		{
			student_query(m);
		}
	
}






