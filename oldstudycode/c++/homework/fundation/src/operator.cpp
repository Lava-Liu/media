/* ==================================================================
 *       Filename:  operator.cpp
 *    Description:  
 *        Created:  2013年11月04日 08时55分59秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
class B;
using namespace std;

class A
{
	public:
		A(){};
		A(int real, int virl):realnum(real), virlnum(virl){}
		~A(){};
		void out()
		{
			cout << realnum << "+" << virlnum << "i" << endl;
		}
		A operator+ (A& a)
		{
			A temp;
			cout << "A+B" << endl;
			temp.realnum=realnum+a.realnum;
			temp.virlnum=virlnum+a.realnum;
			return temp;
		}
	
	private:
		int realnum;
		int virlnum;
};


int main(void)
{
	A a(5, 6);
	A b(5, 6);
	A c(0, 0);
	c=a+b;
	c.out();

	return 0;
}

