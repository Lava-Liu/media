/* ==================================================================
 *       Filename:  div1.cpp
 *    Description:  
 *        Created:  2013年11月04日 14时05分26秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

int mydiv(int a, int b)
{
	if(b ==0 )
	{
		throw 101;
	}
	return a/b;
}
int myException(int a, int b)
{
	try{
		mydiv(a, b);
	}catch(int &a)
	{
		cout << "myException(int )"<<a << endl;
	}
	catch(string &str)
	{
		cout << "myException(string )"<<str << endl;
	}
	cout << "End myException" <<endl;
}


int main(void)
{
	cout << "in mian" <<endl;
	try{
		myException(10, 0);
	}catch(int &a)
	{
		cout << "main(int)"<<a << endl;
	}catch(...)
	{
		cout << "other Exception int main" <<endl;
	}

	cout << "end main"<< endl;
	return 0;
}
