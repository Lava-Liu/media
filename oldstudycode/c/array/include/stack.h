#ifndef _STACK_H_
#define _STACK_H_

typedef int ElementType;
typedef unsigned int size_t;

/*
 * 往栈中放入一个元素，成功返回该元素
 */
ElementType push(ElementType e);
/*
 * 弹出栈顶元素
 */
ElementType pop(void);
//复制获取栈顶元素
ElementType top(void);
//判断栈中元素的个数
size_t size(void);
//判断栈是否为空
int is_empty(void);
//判断栈是否满
int is_full(void);
//输出栈内的元素
ElementType out_stack(int);
#endif
