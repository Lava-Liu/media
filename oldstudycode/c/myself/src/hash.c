#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 10
static ElementType table[ROW][COL+1];
ElementType entable(ElementType e)
{
	int row;
	int col;
	if(is_full())
		exit(1);
	row = e % ROW;
   	if(table[row][0]<COL)
	{
    table[row][table[row][0]+1]=e;
	
	table[row][0]++;
	return e;
	}
	return 0;
}

ElementType checktable(ElementType e)
{
	if(is_empty())
		exit(1);
	    int row;
	    int i;	
		row = row % ROW;
		for(i=1;i<+table[row][0];i++)
		{
			if(table[row][i]==e)
				return i;
			return 0;
		}


}
ElementType remove_element(ElementType e)
{
	int row;
	row=e % ROW;
	int index=checktable(e);
	for(index;index <= table[row][0];index++)
	{
		table[row][index]=table[row][index+1];
	}
	table[row][0]--;
	return 0;
}
size_t  size()
{
	int sum=0;
	int i;
	for(i=0;i<ROW;i++)
	{
		sum+=table[i][0];
	}
	return sum;
}
int is_empty()
{
	if(size()==0)
		return 1;
	return 0;
}
int is_full()
{
	if(size()==ROW*COL)
		return 1;
	return 0;
}
void out_table()
{
	int row;
	int col;
	for(row=0;row<ROW;row++)
	{
		printf("counter:%d\t",table[row][0]);
		for(col=1;col<=table[row][0];col++)
		{
			printf("%d\t",table[row][col]);
		}
		printf("\n");
	}
}


