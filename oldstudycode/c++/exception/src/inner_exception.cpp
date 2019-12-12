/* ==================================================================
 *       Filename:  inner_exception.cpp
 *    Description:  
 *        Created:  2013年11月04日 15时03分57秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

class A
{
	public:
		A():data(0){}
		~A(){}
		class MyExp 
		{
			public:
				MyExp(string str = "unknow Exception"){
					this->str=str;
				}
				~MyExp(){}
				string  what()
				{
					return this->str;
				}
			private:
				string str;
		};
		void show()
		{
			if(this->data == 0)
				throw MyExp("data is 0!");
			cout << "Data:" << this->data <<endl;
		}
		void setData(int data)
		{
			this->data =data;
		}
		int getData()const{
			return this->data;
		}
	private:
		int data;
};

int main(void)
{
	A a;
	try{
		a.show();
		a.setData(0);
	}catch(A::MyExp& p)
	{
		cout << p.what() << endl;
	}
	return 0;
}
