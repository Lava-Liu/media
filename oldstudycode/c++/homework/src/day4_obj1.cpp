/* ==================================================================
 *       Filename:  day4_obj1.cpp
 *    Description:  
 *        Created:  2013年11月05日 19时26分28秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <string.h>
using namespace std;

class String
{
	public:
		String()
		{	
			p=NULL;
		}
		String(char *str)
		{
			p=str;
		}
		~String()
		{

		}
		void display()
		{
			cout << p << endl;
		}
		friend bool operator<(String&a, String&b);
		friend bool operator>(String&a, String&b);
		friend bool operator==(String&a, String&b);
	private:
			char *p;
};

bool operator== (String& a, String&b)
{
	if(!strcmp(a.p, b.p))
	{
		return true;
	}
	return false;
}
bool operator< (String&a , String&b)
{
	if(strlen(a.p)<strlen(b.p))
	{
		return true;
	}
	return false;
}
bool operator> (String&a , String&b)
{
	if(strlen(a.p)<strlen(b.p))
	{
		return true;
	}
	return false;
}

int main(void)
{

	String s("hello");
	String b("hello");
	cout << (s==b) <<endl;
	cout << (s<b) <<endl;
	cout << (s>b) <<endl;

	return 0;
}








