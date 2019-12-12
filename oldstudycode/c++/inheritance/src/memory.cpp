/* ==================================================================
 *       Filename:  memory.cpp
 *    Description:  
 *        Created:  2013年11月05日 10时00分01秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

class Person
{
	public:
		Person(){
			cout << "Person()" <<endl;
		}
		~Person(){
			cout << "~Person()" <<endl;
		}
		void show(){
			cout << "Person::i" << this->i<<endl\
				<<"Person::j" << this->j<<endl;
		}
	protected:
	//private:
		int i;
		int j;
};

class Student : public Person
{
	public:
		Student(){
		cout << "Student()"<<endl;
		}
		~Student()
		{
			cout << "~Student()" << endl;
		}
		void show()
		{
			cout << "Student::data=" << this->data << "\n" << "Person::i" << i << "\n"<<"Person::j" << j << endl;
		}
	private:
		int data;
};

int main(void)
{
	/*Person p;
	cout << "sizeof(p):" << sizeof(p) << endl;
	*((int *)(char *)&p) = 100;
	*((int *)((char *)&p+4))=105;
	p.show();
	return 0;*/
	Student s;
	cout << "sizeof(s)" << sizeof(s) << endl;
	*(int *)(char *)&s = 100;
	*(int *)((char *)&s+4) = 100;
	*(int *)((char *)&s+8) = 100;
	s.show();






	return 0;




}
