#include <stdio.h>
#include "team.h"
#include <stdlib.h>
#define MAX_LEN 100
static member team[MAX_LEN];
size_t counter=0;
int add_member(member* m) 
{
	if(counter < MAX_LEN)
	{
		team[counter++]= *m;
		return 1;
		
	}
	return 0;

}
int delete_member(int code)
{
	member *m = get(code);
	while(m < team + counter-1)
	{
		*m=*(m+1);
		m++;
	}
	counter--;
	return 1;
}
member* get(int code)
{
	int i;
	for(i=0;i<counter;i++)
	{
		if(team[i].person.s.code == code )
			return &team[i];
		return NULL;
	}
}
static void query_teacher(member* m)
{
	printf("code = %d\n,name=%s\n,age= %d\n, salary= %lf\n",m->person.t.code,m->person.t.name,m->person.t.age,m->person.t.salary);
	
	
	

}
static void query_student(member* m)
{
	printf("code = %d\n,name=%s\n,age= %d\n",m->person.s.code,m->person.s.name,m->person.s.age);

}
void query()
{
	int i;
	for(i=0;i<counter;i++)
	{
		if(team[i].id == TEACHER)
		{
			query_teacher(&team[i]);
		}
		if(team[i].id == STUDENT)
		{
			query_student(&team[i]);
		}
	}
}



