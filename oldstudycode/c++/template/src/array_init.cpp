/* ==================================================================
 *       Filename:  array_init.cpp
 *    Description:  
 *        Created:  2013年11月06日 16时27分46秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <cstring>
using namespace std;

template<typename T, int n>
void array_init(T(&array)[n])
{

	for(int i = 0;i<n;i++)
	{
		array[i]=i;
	}
}

template <class T>
int compare(const T &a, const T &b)
{
	cout << "T T" <<endl;
	if(a>b) return 1;
	else if(a<b) return -1;
	return 0;
}

template <>
int compare(char *const &p, char *const &q)
{
	cout << "int compare(<>, <>) " <<endl;
	return strcmp(p, q);
}


int main(void)
{	char array[10];
	array_init(array);
	for(int i=0;i<10;i++)
	{
		cout << "array["<<i <<"]: "<<(int)array[i] <<endl;
	}
	char p='a';
	char s='b';
	char *ptr =&p;
	char *str =&s;
	//传参是两个指针，指针之间的比较是没有意义的
	//需要比较指针返回的字符串
	cout << "compare:" <<compare(ptr, str) <<endl;

	return 0;
}
