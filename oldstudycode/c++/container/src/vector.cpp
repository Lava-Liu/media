/* ==================================================================
 *       Filename:  vector.cpp
 *    Description:  
 *        Created:  2013年11月08日 10时06分16秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <vector>
#include "student.h"

void display(vector<Student> &v)
{
	for(int i=0;i<v.size();i++)
	{
		cout << "----------------" <<endl;
		(v[i]).show();
		
	}	
}

//迭代器顺序遍历
void iter_show(vector<Student> &v)
{
	vector<Student>::iterator iter = v.begin();
	for(;iter != v.end();iter++)
	{
		iter->show();
	}
}
void iter_show2(vector<Student> &v)
{
	vector<Student>::reverse_iterator iter = v.rbegin();
	for(;iter != v.rend();iter++)
	{
		//iter->show();
		cout << *iter << endl;
	}

}

int main(void)
{
	vector<Student> vect;
	Student s1("jack", 1001);
	Student s2("rose", 1002);
	Student s3("lucy", 1003);
	Student s4("toms", 1004);
	cout << "------- push_back --------" <<endl;
	vect.push_back(s1);
	vect.push_back(s2);
	vect.push_back(s3);
	vect.push_back(s4);

	cout << vect.front() << endl;
	 //vect.pop_back();
	cout << vect.back() << endl;

	cout << "------- show vector --------" <<endl;
	//display(vect);
	//iter_show(vect);
	iter_show2(vect);
	vector<Student>::iterator iter = vect.begin();
	vector<Student> v2;
	Student s5("Herry", 1005);
	Student s6("Herry1", 1006);
	Student s7("Herry2", 1007);
	v2.push_back(s5);
	v2.push_back(s6);
	v2.push_back(s7);
	//vect.insert(iter, s5);
	vect.insert(vect.end(), v2.begin(), v2.begin()+2);
	iter_show(vect);
	cout << "-------------" << endl;

	vect.erase(vect.begin()+1, vect.end()-1);
	display(vect);



	return 0;
}


