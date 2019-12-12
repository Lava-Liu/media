#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 5
static ElementType queue[MAX_LEN];
int counter=0;//保存队列中当前元素的个数
int head;//保存队列中队头的位置
int tail;
//元素入队
ElementType enqueue(ElementType e)
{
	if(is_full())
		exit(1);
	
    queue[tail++]=e;
	tail%=MAX_LEN;
	
	counter++;
	return e;



}
static void move_element()
{
	int i = 0;
	for(i;i<counter-1;i++)
	{
		queue[i] = queue[i+1];
	}
}
//元素出队列
ElementType dequeue(void)
{
	if(is_empty())
		exit(1);
	
    ElementType e = queue[head++];
    head%=MAX_LEN;
	//move_element();
	counter--;
	return e;
}
//复制获得队首元素
ElementType cpqueue(void)
{
	return queue[head];
}
//队列的长度
size_t size(void)
{
	return counter;
}
//判断队空
int is_empty(void)
{
	if(counter == 0)
		return 1;
	return 0;
}
//判断队满
int is_full(void)
{
	if(counter== MAX_LEN)
		return 1;
	return 0;
}


