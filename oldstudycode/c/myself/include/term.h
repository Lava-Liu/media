#ifndef _TERM_H_
#define _TERM_H_
enum identify {TEACHER,STUDENT};
typedef struct teacher
{
	int code;
	char name[20];
	int age;
	double salary;
}teacher;
typedef struct student
{
	int code;
	char name[20];
	int age;

}student;
typedef struct member
{
	enum identify id;
	union
	{
		teacher t;
		student s;
	}person;

}member;


extern int add_member(member*);
extern int delete_member(int code);
extern member* get(int code);
extern void query();
extern void out(int code);









#endif
