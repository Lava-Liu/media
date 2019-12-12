/* ==================================================================
 *       Filename:  getline.cpp
 *    Description:  
 *        Created:  2013年11月07日 15时08分09秒
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
	cin.read(buffer, 50);
	//cin.getline(buffer, 20, '*');
	//cin >> buffer;
	cout << buffer << endl;



	return 0;
}
