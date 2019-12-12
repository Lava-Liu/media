/* ==================================================================
 *       Filename:  filestream.cpp
 *    Description:  
 *        Created:  2013年11月07日 16时31分26秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc , char *argv [])
{
	if(argc < 2)
	{
		cerr << "useage: " << argv[0] << " filepath " << endl;
	}
	fstream file;
	file.open(argv[1], ios::in);
	char buffer[100];
	memset(buffer, 0, 100);
	file.read(buffer, 10);
	cout << "buffer: " << buffer << endl;

	file.close();

	return 0;
}
