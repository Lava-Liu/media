/* ==================================================================
 *       Filename:  linst.cpp
 *    Description:  
 *        Created:  2013年11月08日 11时19分37秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include "student.h"
#include <list>

void display(list<Student> &l)

{
	list<Student>::iterator iter = l.begin();
	for(;iter != l.end();iter++)
	{
		cout << *iter << endl;
	}
}

//设置排序的规律
bool Compare(Student &s1 , Student &s2)
{
 if(s1.getNumber() < s2.getNumber())
		return true;
	return false;
}

class Mycompare
{
	public:
		bool operator() (Student &s1, Student &s2)
		{
          if(s1.getNumber() < s2.getNumber())
		         return true;
                	return false;
		}
};

bool remove(Student&s)
{
	if(s.getNumber() == 103)
		return true;
	return false;
}

int main(void)
{

	list<Student> l;
	Student s1("A", 101);
	Student s2("B", 102);
	Student s3("C", 103);
	Student s4("D", 104);
	
	
	l.push_back(s1);
	l.push_front(s2);
	l.push_back(s3);
	l.push_front(s4);
	display(l);
	
	cout << "------------After sort------------" << endl;
	
	//l.sort(Mycompare());
	//display(l);
	l.remove_if(remove);
	display(l);
	return 0;
}
