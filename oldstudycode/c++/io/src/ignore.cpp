/* ==================================================================
 *       Filename:  ignore.cpp
 *    Description:  
 *        Created:  2013年11月07日 15时28分25秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <cstring>
using namespace std;






int main(void)
{

	char buffer[100];
	memset(buffer, 0, sizeof(buffer));
	cin.ignore(10, '#');
	cin.getline(buffer, 10);
    cout << buffer << endl;
	return 0;
}
