/* ==================================================================
 *       Filename:  charioctl.h
 *    Description:  test
 *        Created:  2013年10月21日 13时42分43秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司 (http://www.briup.com)
 * ==================================================================*/
#ifndef __CHARIOCTL_H__
#define __CHARIOCTL_H__

#include <asm/ioctl.h>

//int major =0;
//char *mydevcname = "chardev";

#define MAX_LEN    0x1000
#define TYPE        'J'

//晴空设备所有数据
#define CLR_ALL        _IOWR(TYPE, 0, int) 
//清空设备内部头部的指定字节数
#define CLR_BEGIN      _IOWR(TYPE, 1, int)
//晴空设备内部尾部的制定字节树
#define CLR_END 	   _IOWR(TYPE, 2, int)
//默认设备命令 （清空所有
#define CLR_DFT  CLR_ALL

//ioclt函数存在数据的流动
//将设备内部的数据传递到设备的外部
#define DATA_GET  		_IOWR(TYPE, 10, int)


//默认清空数据的字节数（仅针对CLR_BEGIN和CLR_END)
#define DFT_SIZE 10

#endif
