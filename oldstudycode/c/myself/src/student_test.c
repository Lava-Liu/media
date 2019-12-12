#include <stdio.h>
#include <stdlib.h>
#include "student.h"
void add()
{
	char a[20]={'\0'};
	double b;
	printf("请输入学生的姓名：");
	scanf("%s",a);
	printf("请输入学的的成绩：");
	scanf("%lf",&b);
	if(add_student(a,b))
	{
		printf("add new student success!");
	}else
	{
		printf(" No success!");
		
	}
		
}
void modify()
{
	int a;
	double b;
	printf("请输入要修改学生的学号：");
	scanf("%d",&a);
	printf("请输入新的成绩：");
	scanf("%lf",&b);
	if(modify_student(a,b))
	{
		printf("modify score success！");
	}else
	{
		printf("No success!");
		
	}

}
void query()
{
	int a;
	printf("请输入要查询的学号：");
	scanf("%d",&a);
	query_student(a);
	
}
void show_menu()
{
	printf("-----------------\n");
	printf("--1.添加新学生---\n");
	printf("-—2.修改学生信息-\n");
	printf("--3.查询学生信息-\n");
	printf("--0.退出系统-----\n");
	printf("-----------------\n");
}
int main(void)
{
	while(1)
	{
	char a;
	char ch;
	show_menu();
	while((ch=getchar()!= '\n'))
		continue;
	printf("请输入一个选项：");
	scanf("%c",&a);
	

		switch(a)
		{
			case '1':
				     add();
				     break;
	        case '2':
		             modify();
			         break;
		    case '3':
			         query();
			         break;
		    case '0':
		             printf("系统已经退出！\n");
				     exit(1);
		     default:
		             printf("没有这个选项");
					 break;

		}
	}
	
	
	return 0;
}


