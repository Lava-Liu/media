/* ==================================================================
 *       Filename:  complex.cpp
 *    Description:  
 *        Created:  2013年11月06日 19时36分28秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Complex
{
	public:
		Complex(T real = 0, T virl = 0):real(real), virl(virl){}
		~Complex(){}
		void talk()
		{
			cout << real << ":" << virl << endl;
		}
	private:
		T real;
		T virl;
};


int main(void)
{
    Complex<int>*c = new Complex<int>(1,2);
	c->talk();
	return 0;
}
