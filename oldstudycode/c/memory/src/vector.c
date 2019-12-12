#include "vector.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <memory.h>
#define INT_SIZE 5
//初始化一个动态数组
vector* creat_vector()
{	vector *v= (vector*)malloc(sizeof(vector));
	if(v == NULL) return NULL;
	v->_array = (ElementType * )calloc(INT_SIZE,sizeof(ElementType));
	if(v->_array==NULL)
	{
		free(v);
		return NULL;
	}
	v->_counter = 0;
	v->_max = INT_SIZE;
	return v;
	
}

void destory_vector(vector *v)
{
	if(v!=NULL)
	{
		free(v->_array);
		v->_array = NULL;
		free(v);
		v=NULL;
	}
}


int push_front(vector* v,ElementType*e)
{
	insert_element(v,0,e);
}
int push_back(vector * v,ElementType*e)
{
	insert_element(v,v->_counter,e);
}
static void encapacity(vector*v)
{
	if(v->_counter >= v->_max)
	{
		v->_max+=5;
		ElementType *new_array = (ElementType *)calloc(v->_max,sizeof(ElementType));
		memcpy(new_array,v->_array,v->_counter*sizeof(ElementType));
		//int i;
		//for(i=0;i<v->_counter;i++)
		//{
		//	new_array[i]=v->_array[i];
		//}
		free(v->_array);
		v->_array = new_array;
	}
}
int insert_element(vector* v,int index,ElementType *e)
{
	if(v == NULL||e == NULL) return 0;
	//看是否需要扩展
	encapacity(v);
	int i;
	for(i=v->_counter;i>index;i--)
	{
		v->_array[i]=v->_array[i-1];

	}
	v->_array[index]= *e;
	v->_counter++;
	return 1;
}
int pop_front(vector *v)
{
     remove_element(v,0);
}
int pop_back(vector *v)
{
	remove_element(v,v->_counter-1);
}
int remove_element(vector *v,int index)
{
	if(v == NULL|| index <0) return 0;
		int i;
	for(i = index;i<v->_counter;i++)
	{
		v->_array[i]=v->_array[i+1];
	}
	v->_counter--;
	return 1;
}
ElementType *get_elememt(vector *v,int index)
{
	if(v == NULL || index < 0 ) return NULL;
	return &v->_array[index];
}
size_t size(vector *v)
{
		return v->_counter;
}
void query(vector *v)
{
	int i;
	for(i=0;i<v->_counter;i++)
	{
		printf("%d, ",v->_array[i]);
	}
	printf("\n---------------------------------\n");
}

