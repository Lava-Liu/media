/* ==================================================================
 *       Filename:  bool.cpp
 *    Description:  
 *        Created:  2013年10月30日 20时58分01秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;



int main(void)
{

	bool flag;
	cout <<"sizeof(boll):" <<sizeof(flag) << endl;
    cout << flag << endl;
	flag = true;
	cout << "flag(true)" << flag << endl;
	flag = false;
	cout << "flag(true)" << flag << endl;
	return 0;
}
