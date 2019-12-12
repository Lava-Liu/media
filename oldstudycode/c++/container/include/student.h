/* ==================================================================
 *       Filename:  student.cpp
 *    Description:  
 *        Created:  2013年11月08日 09时56分52秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <iostream>
#include <string>
using namespace std;

class Student
{
	public:
		Student(string name="None", int number = 1001)
		:name(name), number(number)
		{
			//cout << "Student()" << endl;
		}
		~Student(){}

		void show()
		{
			cout << "name: "<<this->name << endl;
			cout << "number: "<<this->number << endl;
		}
		void setName(string name)
		{
			this->name=name;
		}
		void setNumber(int name)
		{
			this->number=number;
		}
		string getName()
		{
			return this->name;
		}
		int getNumber()
		{
			return this->number;
		}
		friend ostream& operator<<(ostream&, Student&);
	private:
		string name;
		int number;

};


ostream& operator<<(ostream& os, Student& s)
{
	os<<"number:" <<s.number<<"  name: "<< s.name;
}



#endif
