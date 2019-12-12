#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
//利用二维数组实现哈希表
#define ROW 5
#define COL 10

static table[ROW][COL+1];

//往表中放入一个元素
ElementType entable(ElementType e)
{
	if(is_full())
	exit(1);
	int row;
	int col;
	row = e % ROW;
    col =table[row][0]+1;
	if(col < COL)
	{
	table[row][col]=e;
	table[row][0]++;
	return 1;
	}
	return 0;
	
	
}
//查找某个元素是否存在
ElementType checktable(ElementType e)
{
	if(is_empty())
		exit(1);
	int row;
	int i;
	row = e % ROW;
	for(i=1;i<=table[row][0];i++)
	{
		if(table[row][i]==e)
			return 1;
		return 0;

	}
}
static int get_index(int row,ElementType e)
{
	if(is_empty())
		exit(1);
	
	int i;
	row = e % ROW;
	for(i=1;i<=table[row][0];i++)
	{
		if(table[row][i]==e)
			return i;
		return 0;

}	
}
//删除某个元素
void remove_element(ElementType e)
{
	if(is_empty())
		exit(1);
	int row;
	int i;
	row = e % ROW;
	for(i=1;i<=table[row][0];i++)
	{
		if(table[row][i]==e)
		{
			for(i;i<=table[row][0];i++)
			table[row][i]=table[row][i+1];
	 	    table[row][0]--;
		}
		
}
}
//表的从元素个数
size_t size()
{
	int sum;
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
	int i;
	int j;
	for(i=0;i<ROW;i++)
	{
		printf("counter:%d\t",table[i][0]);
		for(j=1;j <= table[i][0];j++)
		{
			printf("%d\t",table[i][j]);
		}
		printf("\n");

}
}


