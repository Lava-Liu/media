/* ==================================================================
 *       Filename:  std_exception.cpp
 *    Description:  
 *        Created:  2013年11月04日 15时16分30秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

int mydiv(int a, int b)
{
	if(b == 0)
		throw exception();
	return a/b;
}


int main(void )
{
	try{
		mydiv(10, 0);
	}catch(exception &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
