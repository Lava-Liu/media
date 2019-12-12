#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int ElementType;
typedef unsigned int size_t;
//元素入队
ElementType enqueue(ElementType);
//元素出队列
ElementType dequeue(void);
//复制获得队首元素
ElementType cpqueue(void);
//队列的长度
size_t size(void);
//判断队空
int is_empty(void);
//判断队满
int is_full(void);


#endif
