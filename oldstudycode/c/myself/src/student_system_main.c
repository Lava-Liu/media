#include "student_system.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
void inset()
{
	FILE *fp = fopen("data.txt","rb");
	node *n = (node*)malloc(sizeof(node));
	char *name_out = (char*)malloc(20);
	list *l = creat_list();
	//fread(n,sizeof(node),1,fp);
	while(!feof(fp) && fread(n,sizeof(struct node),1,fp) &&
			fread(name_out,20,1,fp))
	{   
	    //fread(n,sizeof(node),1,fp);
		
		
		
		push_back(l,&n->code,&n->age,name_out,&n->score);
	}
	free(n);
	free(name_out);
	n=NULL;
	name_out=NULL;
	fclose(fp);

}
void insert_student(list*l)
{
	int code;
	int age;
	char *name=(char*)malloc(20);
	double score;
	printf("请输入学生的学号：")；
	scanf("%d",&code);
	printf("请输入学生的年龄：")；
	scanf("%d",&age);
	printf("请输入学生的姓名：")；
	scanf("%s",name);
	printf("请输入学生的成绩：")；
	scanf("%lf",&score);
	if(push_back(l,&code,&age,name,&score)==1)
	{
		printf("添加信息成功！\n");
	}
	
}
void delete_student(list* l)
{
	int del;
	printf("请输入信息列表中该学生信息的位置：\n");
	scanf("%d",&del);
	if(remove_index(l,del)==1)
	{
		printf("删除信息成功！\n");
	}

}
void manu()
{
	printf("<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>\n");
	printf("|      欢迎使用学生信息查询系统        |\n");
	printf("|                                      |\n");
	printf("|      1 添加一位学生的信息            |\n");
	printf("|      2 删除一位学生的信息            |\n");
	printf("|      3 查询学生信息                  |\n");
	printf("|      4 显示所有学生信息 	           |\n");
	printf("|      5 按成绩排序显示                |\n");
	printf("|      6 按年龄排序显示                |\n");
	printf("|      7 按学号排序显示                |\n");
	printf("|      0 退出系统                      |\n");
	printf("<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>\n");
}
int main(void)
{
	inset();
	while(1)
	{
		char num;
	manu();
	printf("请选择要进行的操作：")；
		scanf("%c",&num);
	switch(num)
	{
		case '1':
			insert_student(l);
			break;
		case '2':
			delete_student(l);
			break;
		case '3':
            show_all(l);
			break;
		case '4':
			show_index(l);
			break;
		case '5':
			sort_student(list *l,sort_score);
			break;
		case '6':
			sort_student(list *l,sort_age);
			break;
		case '7':
			sort_student(list *l,sort_code);
			break;
		case '0':
			printf("系统已经退出欢迎下次使用！\n");
			exit(1);
		default :
			printf("没有这个选项请重新选择！\n");
			break;
	}

	printf("%d\n",size(l));
    
	query(l);
	data(l);
	destroy_list(l);
	return 0;
}
