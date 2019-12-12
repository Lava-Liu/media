/* ==================================================================
 *       Filename:  string.cpp
 *    Description:  
 *        Created:  2013年11月07日 17时12分43秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;


int main(void)
{
	istringstream iss;
	char buffer[100];
	memset(buffer, 0, sizeof(buffer));
	string s = "Hello world";
	//iss.str(s);
	iss << s;
	//iss >> buffer;
	iss.getline(buffer, 100);


	cout << "buffer: " << buffer << endl;



	return 0;
}
