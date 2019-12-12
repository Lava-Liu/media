/* ==================================================================
 *       Filename:  day6_obj2.cpp
 *    Description:  
 *        Created:  2013年11月04日 19时33分54秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <string.h>
using namespace std;


class Person
{
	protected:
		char *m_szname;
		char *m_szid;
		bool  m_gender;
		int   m_age;
	public:
		Person(char *name, char *id, bool sex, int age)
		{
			this->m_szname = new char[strlen(name)+1];
			strcpy(m_szname, name);
			this->m_szid   = new char[strlen(id)+1];
			strcpy(m_szid, id);
			this->m_gender = sex;
			this->m_age    = age;
		}
		void show()
		{
			cout << "name:" << m_szname <<endl\
				<< "m_szid" << m_szid <<endl\
				<< "m_gender" <<(m_gender=1?"male":"female")<<endl\
				<< "age:"  << m_age <<endl;
		}
		~Person(){
			delete []m_szname;
			delete []m_szid;
		}
};

class Employee:public Person
{
	private:
		char *m_szdepartment;
		float m_salary;
	public:
		Employee(char *name, char *id, bool sex, int age, char *department, float salary):Person(name, id, sex, age)
		{
			this->m_szdepartment = new char[strlen(department)+1];
			strcpy(m_szdepartment, department);
			this->m_salary = salary;
		}
		~Employee(){
			delete []m_szdepartment;
		}
		void show2()
		{
			cout << "name:" << m_szname <<endl\
				<< "m_szid" << m_szid <<endl\
				<< "m_gender" <<(m_gender=1?"male":"female")<<endl\
				<< "age:"  << m_age <<endl\
				<< "salary:" << m_szdepartment <<endl\
				<< "department" << m_szdepartment <<endl;
			
		}
};

int main(void)
{
	char name[10], id[19], department[10];
	bool sex;
	int age;
	float salary;
	cout << "input name id department sex age salary" <<endl;
	cin >> name >> id >> sex >> age >> department >> salary;
	Employee e1(name, id, sex, age , department, salary);
	e1.show2();
	return 0;

}
















