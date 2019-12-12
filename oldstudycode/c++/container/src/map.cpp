/* ==================================================================
 *       Filename:  map.cpp
 *    Description:  
 *        Created:  2013年11月08日 13时54分01秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include "student.h"
#include <map>


void display(map<int, Student> &m)
{
	map<int , Student>::iterator iter = m.begin();
	while(iter != m.end())
	{
		
		cout << iter->first << endl;
		cout << iter->second << endl;
		iter++;
	}

}


int main(void)
{
	map<int , Student>  m;

	Student s1("A", 101);
	Student s2("B", 102);
	Student s3("C", 103);
	Student s4("D", 104);
	
	m.insert(pair<int, Student>(1, s1));
	m.insert(pair<int, Student>(2, s2));
	m.insert(pair<int, Student>(3, s3));
	m.insert(pair<int, Student>(4, s4));
	
	map<int, Student>::iterator it=m.find(3);
	
	cout << it->first << endl;
	cout << it->second << endl;


	return 0;
}
