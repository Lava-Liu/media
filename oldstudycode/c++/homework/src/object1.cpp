/* ==================================================================
 *       Filename:  object1.cpp
 *    Description:  
 *        Created:  2013年11月04日 18时31分11秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

class Rectangle
{
	public:
		Rectangle():length(1), width(1){}
		Rectangle(double x, double y):length(x), width(y){}
		void isSquare()
		{
			if(this->length == this->width)
			{
				cout << "this is a square!" << endl;
			}else
			{
				cout << "this is not a square!"<<endl;
			}
		}
		double getPerimeter()
		{
			return (this->length+this->width)*2;
		}
		double getArea()
		{
			return this->length*this->width;
		}
	private:
		double length;
		double width;

};



int main(void)
{
	Rectangle r(10.0, 10.0);
	r.isSquare();
	cout << "Perimeter:"<<r.getPerimeter() << endl\
		<< "Area:"<<r.getArea() <<endl;

	return 0;
}
