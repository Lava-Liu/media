#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("student.txt","r");
	int code;
	char name[20]={'\0'};
	int age;
	int i;
	for(i=0;i<3;i++)
	{	
		fscanf(fp,"%d%s%d",&code,name,&age);
		printf("%d,%s,%d\n",code,name,age);
	}
	fclose(fp);
		return 0;
}
