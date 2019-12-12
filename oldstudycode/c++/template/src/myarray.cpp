/* ==================================================================
 *       Filename:  myarray.cpp
 *    Description:  
 *        Created:  2013年11月07日 10时51分28秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <string>
using namespace std;


template <typename T>
class Myarray
{
	public:
		Myarray(int len = 0)
			:_length(len)
		{
			this->array = new T[this->_length];
		}
		~Myarray()
		{
			delete[] this->array;
		}
		
		T& operator[] (int index)
		{
			if(index < 0 || index > this-> _length)
				throw string("Out of Rangle");
			return this->array[index];
		}
		template <typename E>
		friend ostream& operator<<(ostream&, Myarray<E>&);
	private:
		T *array;
		int  _length;
};

template <typename T>
ostream& operator<<(ostream& os, Myarray<T> &m)
{
	for(int i=0;i<m._length;i++)
	{
		os << m.array[i] << endl;
	}
	return os;
}

int main(void)
{

	Myarray<int>a(10);
	try{
		a[4]=24;
		a[10]=32;
	}catch(string &str)
	{
		cout << str << endl;
	}
    cout << a << endl;
	return 0;
}
