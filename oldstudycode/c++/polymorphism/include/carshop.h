/* ==================================================================
 *       Filename:  carshop.h
 *    Description:  
 *        Created:  2013年11月05日 16时00分30秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司 (http://www.briup.com)
 * ==================================================================*/
#ifndef __CARSHOP_H__
#define __CARSHOP_H__
#include "carfactory.h"

class CarShop
{
	public:
		CarShop(string name="module");
		~CarShop();
		
	Car* getCar() const{
		cout << "得到汽车" << endl;
		return this->cf->sale();
	}
	private:
		string        name;
		CarFactory    *cf;
};




#endif
