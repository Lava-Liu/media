#ifndef _TEAM_H_
#define _TEAM_H_

enum identify {TEACHER,STUDENT};

typedef struct student
{
	int code;
	char name[20];
	int age;
}student;
typedef struct teacher
{
	int code;
	char name[20];
	int age;
	double salary;
}teacher;
typedef struct member
{
	enum identify id;
	union
	{
		student s;
		teacher t;
	}person;
}member;
extern int add_menber(member*);
extern int delete_member(int code);
extern member* get(int code);
extern void query();




#endif
