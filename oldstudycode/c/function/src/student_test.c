#include "student.h"
#include <stdio.h>
#include <srdlib.h>

void enter_message()
{
	char name[20] = {'\0'};
	double score;
	printf("请输入学生姓名：");
	scanf("%S",name);
	printf("请输入学生成绩：");
	scanf("%lf",&score);
	if(add_student(name,score))
	{
		printf("add new sutudent success!\n");

	}else
		exit(1);
}
void modify()
{
	int num;
	double score;
	printf("");
	scanf("%d",&num);
	printf("");
	scanf("%d",&score);
	if(modify_score(num,score))
	{
		printf("success!\n");
	}
	exit(1);
}
void show_menu()
{
	printf("---------------------\n");
	printf("----- 1.添加学生-----\n");
	printf("------2.修改成绩-----\n");
	printf("------3.查询信息-----\n");
	printf("------0.退出系统-----\n");
}
void query()
{
	printf("");
	int num;
	scanf("%d",&num);
	query_student(num);
}
int main(void)
{
	while(1)
	{
		show_menu();
		printf("")；
		char c;
		scanf("%c",c);
		switch(c)
		{
			case '1':
				enter_message();
				break;
			case '2':
				modify();
				break;
			case '3':
			    query();
				break;
			case '0':
				printf("系统退出！")；
					exit(1);
			default:
				printf("没有这个选项！")；

		}
	}



	return 0;
}
