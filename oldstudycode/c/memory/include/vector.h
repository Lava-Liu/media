#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef int  ElementType;
typedef unsigned int size_t;
typedef struct vector
{
	ElementType *_array;
	int          _counter;
	int          _max;
}vector;

//创建动态数组
extern vector * creat_vector();

extern void destory_vector(vector *v);

extern int push_front(vector* v,ElementType*e);
extern int push_back(vector * v,ElementType*e);
extern int insert_element(vector* v,int index,ElementType *e);
extern int pop_front(vector *v);
extern int pop_back(vector *v);
extern int remove_element(vector *v,int index);
extern ElementType *get_elememt(vector *v,int index);
extern size_t size(vector *v);
extern void query(vector *v);

#endif
