/* ==================================================================
 *       Filename:  namespace.cpp
 *    Description:  
 *        Created:  2013年10月28日 14时16分58秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;


namespace briup
{
	int number = 100;
	void out(int n)
	{
		cout << "briup1: " << n << endl;
	}
	//命名空间的嵌套
	namespace briup3 {
		int number = 300;
		void out(int n)
		{
		   cout << "briup3: " << n << endl;
		}
	}
};

namespace briup2
{
	int number = 500;
	void out(int n)
	{
		cout << "briup2: " << n << endl;
	}
};

//匿名的命名空间
//内部定义的数据再当前模块内全局可用
//实现了数据对外的隐藏
namespace 
{
	int number = 10;
	
}

//命名空间定义别名
namespace Br = briup; 


//指定当前模块默认使用的命名空间
//using namespace Br;
int main(void )
{
	//briup::out(briup2::number);
	briup::out(number);
	briup::briup3::out(number);
	return 0;
}
