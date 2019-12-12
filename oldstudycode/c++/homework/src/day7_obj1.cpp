/* ==================================================================
 *       Filename:  day7_obj1.cpp
 *    Description:  
 *        Created:  2013年11月06日 19时07分30秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
	public:
		Point():x(0), y(0){}
		Point(double x0, double y0):x(x0), y(y0){}
		void PrintPoint()
		{
			cout << "dirent:<" << x << ":" << y << ">" << endl; 
		}
		double x, y;
};

class Line:public Point
{
	public:
		Line(Point pt1, Point pt2)
		{
			this->pts=pt1;
			this->pte=pt2;
			this->x=((pt1.x)-(pt2.x));
			this->y=((pt1.y)-(pt2.y));
		}
		~Line(){}
		void printline()
		{
			cout << "point1: "<<pts.x << ":" << pts.y << endl;
			cout << "point2: "<<pte.x << ":" << pte.y << endl;
			cout << "pointmid: "<< x << ":" << y << endl;
		}
	private:
		Point pts, pte, ptm;

};


int main(void)
{
	Point a(1, 2), b(2, 3);
	Line  c(a, b);
	c.printline();
	return 0;
}








