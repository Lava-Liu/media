#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int code[100];
static char name[100][NAME_LEN+1];
static double score[100];
int counter=0;//现实已经存放的学生数
int num = CODE;


int add_student(char *myname,double myscore)
{
	if(counter<100)
	{
		code[counter] = num++;
		int len;
		len = strlen(myname)<NAME_LEN?strlen(myname):NAME_LEN;
		strncpy(name[counter],myname,len);
		if(myscore >= SCORE )
			score[counter]=myscore;
		    counter++;
			return 1;
	}
	return 0;

}
int modify_student(int mycode,double newscore)
{
	int i;
	i=mycode-1000;
	
	if(i >= 0 && i < counter)
	   {
		   score[i]=newscore;
		   return 1;
	   }
	       return 0;
		

}
int query_student(int mycode)
{
	int i;
	i=mycode-1000;
	if(i >= 0 && i <counter)
	{
		printf("学号： %d\n",code[i]);
		printf("姓名： %s\n",name[i]);
		printf("分数： %lf\n",score[i]);
		return 1;
	}
	return 0;


	    

}




