/* ==================================================================
 *       Filename:  template_class1.cpp
 *    Description:  
 *        Created:  2013年11月06日 17时07分28秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

template <typename T>
class A
{
	public:
		A(T data = 0)
		:data(data)
		{
			cout << "A(T data)" << endl;
		}
		~A(){}

		T getData()const{
			return this->data;
		}
		void setData(T data)
		{
			this->data = data;
		}
		template <typename E>
		friend E getAData(A<E>&);
	private:
		T data;
};

template <typename T>
T getAData(A <T>&a)
{
	return a.data;
}

int main(void)
{
	A<int>a(100.01);
	cout << a.getData() << endl;
	cout << getAData(a) <<endl;;
	return 0;
}
