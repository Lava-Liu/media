/* ==================================================================
 *       Filename:  div2.cpp
 *    Description:  
 *        Created:  2013年11月04日 14时19分09秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <string>
using namespace std;

class MyException
{
	public:
		MyException(string str = "Notype of exception")
		{
			cout << "MyException()" << endl;
			this->str = str;
			if(this->str == "Hello")
			throw MyException("init out of normal!");
		}
		~MyException(){
		cout << "~MyException" << this->str<<endl;
		}

		string what()
		{
			return this->str;
		}
	private:
		string str;

};

int mydiv(int a, int b)
	{
		if(b==0)
			throw MyException("hello world!");
		return a/b;
	}


int main(void)
{
	try{
		MyException e1("Hello");
	 //mydiv(10, 0);
	}catch(MyException& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
