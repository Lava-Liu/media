/* ==================================================================
 *       Filename:  const_cast.cpp
 *    Description:  
 *        Created:  2013年10月28日 15时19分17秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

int myadd(int x, int y)
{
	return x+y;
}
int myadd1(const int x, const int y)
{
	int c = x+y;
	return c;
	//将c的结果作为函数的状态进行返回
}

char * out(char ** fmt)
{
	cout << *fmt << endl;
	return ++(*fmt);
}


int main(void)
{
	const char *str ="hello";
	char *ptr = "world";
	//const_cast去掉str 内存访问时候的链接属性
	
	//out(const_cast<char**>(&str));
	out(&ptr);
	cout << ptr << endl;
	//cout << str << endl;
    

	const int a = 10, b =20;
	int sum = 0;
	sum = myadd(a, b);
	cout << "sum:" << sum <<endl;
	
	int a1=20, b1=50;
	sum=myadd(a1, b1);
	cout << "sum2:" << sum <<endl;
	
	return 0;
}
