/* ==================================================================
 *       Filename:  iomanip.cpp
 *    Description:  
 *        Created:  2013年11月07日 16时43分21秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	
	double  a = 10244.001;
	
	//cout <<  setw(20) << "Hello" <<endl;
	//cout <<  setw(20) << setbase(ios::left)<<"Hello" <<endl;
	//cout << setw(20)  << setbase(16) << a << endl;

	//cout << setw(20) << setfill('$') << "hello" << endl;

	cout << scientific << a << endl;
	cout << showpos << a << endl;
	cout << uppercase << "hello" << endl;
	cout << uppercase << hex << 10 <<endl;
	cout << showbase << a << endl;
	double b = 3;
	cout << "--------------------" << endl;
	cout << b << endl;
	cout << showpoint << b << endl;
	



	return 0;
}
