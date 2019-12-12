/* ==================================================================
 *       Filename:  peek.cpp
 *    Description:  
 *        Created:  2013年11月07日 15时38分12秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
	char buffer[100];
	memset(buffer, 0, 100);
	int a = cin.peek();
	cout << a << endl;
	
	char ch;
	cin.get(ch);
	cout << ch << endl;
	
	cin.putback('#');
	cin.putback('*');
	cin.get(buffer, 20);
	cout << buffer << endl;

	return 0;
}

