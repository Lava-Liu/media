#include <stdio.h>

typedef struct student
{
	int code;
	char name[20];
	int age;
}student;

int main(void)
{
	student s = {1,"liuwei",22};
	int i = 10;
	FILE *out=fopen("a.txt","wb");
	fwrite(&s,sizeof(student),1,out);
	
	fclose(out);
	FILE *in = fopen("a.txt","rb");
	student s2;
	fread(&s2,sizeof(s2),1,in);
	fclose(in);
	printf("%d-%s-%d\n",s2.code,s2.name,s2.age);
	return 0;
}
