#include <stdio.h>
typedef struct student
{
	int code;
	char name[20];
	int age;
	double score;
}student;
typedef student ElementType;
ElementType array[5]={
	{1000,"liuwei",22,99.9},
	{1001,"xiaoming",32,49.9},
	{1002,"jame",42,69.9},
	{1003,"tom",62,29.9},
	{1004,"baby",12,89.9}


};
void out(ElementType a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d,%d,%lf,%s\n",a[i].code,a[i].age,a[i].score,a[i].name);
	}
	printf("\n");
}

int code_comp(ElementType*s1,ElementType *s2)
{
	return s1->code - s2->code;
}
int age_comp(ElementType*s1,ElementType *s2)
{
	return s1->age - s2->age;
}
int score_comp(ElementType*s1,ElementType *s2)
{
	return s1->score - s2->score;
}
void insert_sort(ElementType a[],int n,
		int (*comp)(ElementType*,ElementType *))
{
	int i;
	int j;
	ElementType temp;
	for(i=0;i<n;i++)
	{ 
		temp=a[i];
		for(j=i;j>0;j--)
		{
			if(comp(&a[j-1],&temp)<0)
				a[j]=a[j-1];
			else
				break;
		}
		a[j]=temp;
	}
}
int main(void)
{
	int  n=sizeof(array)/sizeof(ElementType);
	out(array,n);
	insert_sort(array,n,code_comp);
	out(array,n);
	insert_sort(array,n,score_comp);
	out(array,n);
	insert_sort(array,n,age_comp);
	out(array,n);
	return 0;
}
