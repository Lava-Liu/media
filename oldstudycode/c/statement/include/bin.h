#ifndef _BIN_H_
#define _BIN_H_


extern void out_bin(int);
extern void out_bin_any(void *p, int n);
extern void out_char(char);
//把一个int型数据的第n位置1
extern void set_bit(int *p,int n);
//把一个数的第n为清0
extern void clr_bit(int *p,int n);
#endif
