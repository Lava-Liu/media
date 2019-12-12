/* ==================================================================
 *       Filename:  student_test.cpp
 *    Description:  
 *        Created:  2013年11月04日 17时10分27秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

class Person //作为基类出现
{	
	public:
		Person():weight(0), height(0), gender(true), name("None"), age(0)
	{
		cout << "Person()" << endl;
	}
		Person(string name, int age):weight(0), gender(true), height(0){
			cout << "Person(string , int)"<<endl;
			this->name=name;
			this->age=age;
		}
		~Person()
		{
			cout << "~Person()" << endl;
		}
	//private:
	protected:
		double  weight;
		double  height;
		string  name;
		bool    gender;
		int     age;
};
class Student : public Person
{
	public:
		Student():st_no(1001){
		cout << "Student()" << endl;
		}
		Student(string name, int age, int st_no):Person(name, age){
			cout << "Student(string , int , int )" << endl;
			this->st_no=st_no;
			//Person(name, age);
		}
		~Student(){
			cout << "~Student()" <<endl;
		}
		void show()
		{
			cout << "学号:" << this->st_no << endl\
				<< "姓名" << name << endl\
				<< "年龄" <<age << endl;
		}
	private:
		int st_no;
};



int main(void)
{
	Student s("Rose", 23, 100005);
	s.show();

	
	return 0;
}
