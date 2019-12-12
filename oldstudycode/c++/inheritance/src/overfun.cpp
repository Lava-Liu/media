/* ==================================================================
 *       Filename:  overfun.cpp
 *    Description:  
 *        Created:  2013年11月05日 09时42分10秒
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
		cout << "Person()" << endl;
		}
		~Person(){
			cout << "~Person()" << endl;
		}
		void talk()
		{
			cout << "Person::talk()" << endl;
		}
	private:
};
class Student :public Person
{
	public:
		Student(){
			cout << "Student()"<<endl;

		}
		~Student(){
			cout << "~Student" << endl;
		}
		void talk(int i)
		{
			cout << "Student::talk()"<<endl;
		}
	private:

};
int main(void)
{

	Student s;
	s.talk(1);

	return 0;
}















