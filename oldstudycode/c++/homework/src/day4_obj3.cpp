/* ==================================================================
 *       Filename:  day4_obj3.cpp
 *    Description:  
 *        Created:  2013年11月05日 20时04分59秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

class Complex
{
	public:
		Complex(int re=0, int vi=0)
			:real(re), virl(vi)
		{

		}
		void display()
		{
			cout << real <<"+"<<virl<<"i"<<endl;
		}
		friend ostream& operator<<(ostream& os,const Complex& p);
		friend istream& operator>>(istream& is,const Complex& p);
	private:
		int real;
		int virl;
};


ostream& operator<<(ostream& os,const Complex &p)
{
	os<< p.real << "+" << p.virl << "i";
	return os;
}

istream& operator>>(istream& is,const Complex &p)
{
	is >> p.real >> p.virl;
	return is;
}

int main(void)
{

	Complex a(1, 3), b(1, -3);
	a.display();
	cout << a << endl;
	cout << b << endl;
	return 0;
}

