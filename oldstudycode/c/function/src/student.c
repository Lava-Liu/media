#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int code[100];
static char name[100][NAME_LEN+1];
static double score[100];
int counter = 0; //当前有多少个学生
int num = 1000;
int add_student(char*myname,double myscore)
{
	if(counter<100)
	{
		
		code[counter] = num++;
		int len=((strlen(myname)<NAME_LEN)?strlen(myname):NAME_LEN);
        strncpy(name[counter],myname,len);
	    score[counter]= myscore;
	    counter++;
		return 1;	
		
	}
	return 0;
}
static int get_index(int mycode)
{
	int i;
	for(i=0;i<counter;i++)
	{
		if(code[i]==mycode)
			return i;
	}
	return -1;
}

int modify_score(int mycode, double newscore)
{
		int index = get_index(mycode);
			if(index < 0) return 0;
				score[index] = newscore;
				    return 1;	
}
int query_student(int mycode)
{
	int index = get_index(mycode);
	printf("code:%d\n",mycode);
	printf("name:%s\n",name[index]);
	printf("score:%lf\n",score[index]);

}



