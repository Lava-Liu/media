/* ==================================================================
 *       Filename:  hello.cpp
 *    Description:  
 *        Created:  2013年10月28日 11时17分16秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include "a.txt"
	//int counter = 100;
using namespace std;

int main(void )
{
	cout << "Hello World" << endl;
	cout << "counter:"   << counter << endl;
	int a =100;
	cout.fill('$');
	cout << "a:" << hex << a << endl;
	cout.width(15);
	cout << a << endl;
	cout << left << a << endl;
	sleep(5);
	return 0;
}
