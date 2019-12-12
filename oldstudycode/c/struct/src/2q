#include <stdio.h>
//#pragma pack(1)
typedef struct birthday
{
	char year;
	short month;
	//double day;
	
}birthday;
typedef struct 
{
	int code;
	char name[20];
	double score;
	struct birthday date;
}student;
void out( student *s)
{
    printf("学号： %d\n",s->code);	
    printf("姓名： %s\n",s->name);	
    printf("成绩： %lf\n",s->score);	

}
void out_a( student a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		out(&a[i]);
	}
}
int main(void)
{
	student s_array[3];
	student s1={1000,"liuwei",100};
	student s2={1001,"zhudafeng",100};
	student s3={1002,"zhangmin",100};
	s_array[0]=s1;
	s_array[1]=s2;
	s_array[2]=s3;
	out_a(s_array,3);
	printf("%d\n",sizeof(birthday));
   /* printf("请输入学号：");
    scanf("%d",&(s1.code));
    printf("请输入姓名：");
    scanf("%s",s1.name);
    printf("请输入分数：");
    scanf("%lf",&(s1.score));
    printf("------------------------\n");
	out(&s1);
   // printf("学号： %d\n",s1.code);	
   // printf("姓名： %s\n",s1.name);	
   // printf("成绩： %lf\n",s1.score);*/	

	return 0;
}





	
