/* ==================================================================
 *       Filename:  myled.h
 *    Description:  
 *        Created:  2013年10月22日 16时25分44秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司 (http://www.briup.com)
 * ==================================================================*/
#ifndef __MYLED_H__
#define __MYLED_H__

#include <asm/ioctl.h>

static int counter = 1;
char *led_name = "myled";
static int major = 0;

#define TYPE     'L' 
#define LED_ON   _IOWR(TYPE, 0, int)
#define LED_OFF  _IOWR(TYPE, 1, int)



#endif
