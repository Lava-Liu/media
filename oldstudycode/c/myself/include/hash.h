#ifndef _HASH_H_
#define _HASH_H_
typedef int ElementType;
typedef unsigned int size_t;

ElementType entable(ElementType e);
ElementType checktable(ElementType e);
ElementType remove_element(ElementType e);
size_t  size();
int is_empty();
int is_full();
void out_table();


#endif
