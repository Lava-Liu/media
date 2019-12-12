/* ==================================================================
 *       Filename:  cin1.cpp
 *    Description:  
 *        Created:  2013年11月07日 14时19分14秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

int main(void)
{
	//nt a, b, c;
	//char ch, ch2, ch3;
	
	//cin >> a >> b >> c >>ch;
	//a = cin.get();
	//b = cin.get();
	//cin.get(ch).get(ch2).get(ch3);
	//cout << ch << " "<< ch2 << " "<< ch3 <<endl;
	
	char ch1;
	char buffer[100] = {};
	cin.get(buffer, 10, '#');
	cin.get(ch1);


	cout << buffer << endl << ch1 <<endl;








	return 0;
}
