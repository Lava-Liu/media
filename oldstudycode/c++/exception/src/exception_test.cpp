/* ==================================================================
 *       Filename:  exception_test.cpp
 *    Description:  
 *        Created:  2013年11月04日 13时34分51秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <string>
using namespace std;

int myFun(void)
{
	cout << "myFun" << endl;
	//throw "Big wrong!";
	//throw 100;
	throw string("give me five!");
	cout << "After throw!" <<endl;

	return 0;
}

int main(void)
{
	cout << "In main" << endl;
	try{
		myFun();
	}catch(string &st){
		cout << st << endl;
	}
	catch(char const* str)
	{
		cout << str << endl;
	}
	catch(int& a) //小括号里是一个能够存放异常的变量
	{
		cout << a << endl;
	}catch(...)
	{
		cout << "unkonw exception" <<endl;
	}
	cout << "end main" <<endl; 

	return 0;
}
