/* ==================================================================
 *       Filename:  containerof.c
 *    Description:  test
 *        Created:  2013年10月21日 16时05分37秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <linux/kernel.h>
//#define mycontainerof(addr, type, member)   { size_t len = offsetof(type, member);(type*)((char *)(addr) - len);}

//char *str ="hellow";
//char *p(0x0000804c) =str;

#define myoffsetof(type, member) \
	(ssize_t)&((((type *)0)->member));

#define mycontainer_of(addr, type, member) ({          \
	 const typeof( ((type *)0)->member) *__addr = (addr);  \
	(type *)( (char *)__addr - offsetof(type, member) );})

int main(void)
{
	struct  myType 
	{
		int  a;
		int  b;
		char c;
	};
    struct myType t1 = {100,25,'g'};
    char *ptr = &t1.c;
	struct myType* addr=mycontainer_of(ptr,struct myType,c);
	printf("addr_a:%d\n", addr->a);
	printf("addr_b:%d\n", addr->b);
	printf("addr_c:%c\n", addr->c);

	//int i = myoffsetof(Type, c);
	//printf("i=%d\n", i);
	//typeof(t1.c) tmpc = t1.c;
	//printf("typeof_c: %c\n", tmpc);
	return 0;
}
