#ifndef _HASH_H_
#define _HASH_H
typedef int ElementType;
typedef unsigned int size_t;
//往表中放入一个元素
extern ElementType entable(ElementType e);
//查找某个元素是否存在
extern ElementType checktable(ElementType e);
//删除某个元素
extern void remove_element(ElementType e);
//表的从元素个数
extern size_t size();
//判断是否为空
extern int  is_empty();
//判断是否为满
extern int is_full();
extern void out_table();



#endif
