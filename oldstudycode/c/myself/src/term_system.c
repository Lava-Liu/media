#include "term.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void show_menu()
{
	printf(">>>>>>>>>><<<<<<<<<<<\n");
	printf("|  1.添加学生成员   |\n");
	printf("|  2.添加教师成员   |\n");
	printf("|  3.删除成员信息   |\n");
	printf("|  4.查询成员信息   |\n");
	printf("|  5.全部成员信息   |\n");
	printf("|  0.退出系统       |\n");
	printf("|                   |\n");
	printf(">>>>>>>>>><<<<<<<<<<<\n");
}
void add_s()
{
	member m;
	int code;
	char name[20];
	int age;
	printf("请输入学生的学号：");
	scanf("%d",&code);
	printf("请输入学生的姓名：");
	scanf("%s",name);
	printf("请输入学生的年龄：");
	scanf("%d",&age);
	m.id=STUDENT;
	m.person.s.code=code;
	strcpy(m.person.s.name,name);
	m.person.s.age=age;
	if(add_member(&m)==1)
	{
		printf("add member success!\n");
	}else
	{
		printf("add member false!\n");
	}
}
void add_t()
{
	member m;
	int code;
	char name[20];
	int age;
	double salary;
	printf("请输入教师的编号：");
	scanf("%d",&code);
	printf("请输入教师的姓名：");
	scanf("%s",name);
	printf("请输入教师的年龄：");
	scanf("%d",&age);
	printf("请输入教师的薪水：");
	scanf("%lf",&salary);
	m.id=TEACHER;
	m.person.t.code=code;
	strcpy(m.person.t.name,name);
	m.person.t.age=age;
	m.person.t.salary=salary;
	if(add_member(&m)==1)
	{
		printf("add member success!\n");
	}else
	{
		printf("add member false!\n");
	}
}
void del_m()
{
	int code;
	printf("请输入要删除的成员的编号：");
	scanf("%d",&code);
	if(delete_member(code)==1)
	{
		printf("delete success!\n");
	}else
	{
		printf("delete false!\n");
	}
}
void out_m()
{	int code;
	printf("请输入要察看的成员编号：");
	scanf("%d",&code);
	out(code);
}
int main(void)
{
	while(1)
	{
      char a;
	  char ch;
	  show_menu();
	  while((ch=getchar())!='\n')
		  continue;
	  
	  printf("请输入需要进行的操作：");
	  scanf("%c",&a);
	  switch(a)
	  {
		  case '1':
			  add_s();
			  break;
		  case '2':
			  add_t();
			  break;
		  case '3':
			  del_m();
			  break;
          case  '4':
			  out_m();
			  break;
		  case '5':
			  query();
			  break;
		  case '0':
			  printf("您已退出系统 欢迎下次使用 \n");
			  exit(1);
		  default :
			  printf("没有这个选项！请输入一个正确的选项！\n");
			  break;

	  }
		
		
		
		
	}
	return 0;
}
