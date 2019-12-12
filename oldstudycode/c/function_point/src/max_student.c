#include <stdio.h>

typedef struct studen
{
	int code;
	char name[20];
	int age;
	double score;
}student;


student array[5]=
{
	{1000,"liuwei",20,99.9},
	{1001,"lilei",30,88.9},
	{1002,"xiaoming",10,61.9},
	{1003,"terry",50,55.9},
	{1004,"jack",40,88.9}
	
};
out(student*s)
{
	printf("%d,%d,%s,%lf, \n",s->code,s->age,s->name,s->score);
}
int code_comp(student*s1,student *s2)
{
	return s1->code-s2->code;
}
int age_comp(student *s1,student* s2)
{
	return s1->age-s2->age;
}
int score_comp(student*s1 ,student*s2)
{
	return s1->score-s2->score;
}
student* max_student(student *array,int n,int (*comp)(student*,student*))
{
	student *m=&array[0];
	int i=1;
	for(i;i<n;i++)
	{
		if(comp(&array[i],m)>0)
			m=&array[i];
	}
	return m;
}


int main(void )
{   student* m = max_student(array,5,code_comp);
	
	out(m);
   m = max_student(array,5,age_comp);
   out(m);
    m = max_student(array,5,score_comp);
	out(m);
	return 0;
}
