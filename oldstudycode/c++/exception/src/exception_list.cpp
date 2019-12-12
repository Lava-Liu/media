/* ==================================================================
 *       Filename:  exception_list.cpp
 *    Description:  
 *        Created:  2013年11月04日 14时42分06秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <string>
using namespace std;

//自定义异常说明
// 对函数向上传递异常的类型的限定
// 对不符合异常类型列表限定的异常直接抛给操作系统
int mydiv(int a, int b) throw(int, string)
{
	if(b == 0)
		throw string("Hello");
	return a/b;
}



int main(void)
{

	try{
		mydiv(10, 0);

	}catch(int &i)
	{
		cout << "Main:" << i << endl;
	}catch(string &str)
	{
		cout << "Main(string)" << str << endl;
	}
	return 0;
}
