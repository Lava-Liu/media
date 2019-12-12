/* ==================================================================
 *       Filename:  day4_obj2.cpp
 *    Description:  
 *        Created:  2013年11月05日 19时40分50秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

class Time
{
	public:
		Time(int min=0, int sec=0)
			:minute(min), sec(sec)
		{}
		~Time(){}
		void display()
		{
			cout << minute << ":" << sec <<endl;
		}
		Time& operator++()
		{
			cout << "++oerator" <<endl;
			sec++;
			if(sec==60)
			{
				minute++;
				sec=1;
			}
			return *this;
		}
		Time& operator++(int )
		{
			cout << "operator++" <<endl;
			sec++;
			if(sec==60)
			{
				minute++;
				sec=1;
			}
			return *this;
		}
	private:
		int minute;
		int sec;

};

int main(void)
{

	Time t(3,13),n;
	n = t++;
	t.display();
	n.display();
	n = ++t;
	t.display();
	n.display();
	return 0;
}








