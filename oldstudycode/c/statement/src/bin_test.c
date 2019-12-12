#include <stdio.h>
#include "bin.h"
int main(void)
{
	int a= 2;
	int b = -2;
	out_bin(a);
	out_bin(b);

	out_bin_any(&a,sizeof(a));
	out_bin_any(&b,sizeof(b));
	short int c = 3;
	out_bin_any(&c,sizeof(c));
	set_bit(&a,8);
	out_bin_any(&a,sizeof(a));
	clr_bit(&b,10);
	out_bin_any(&b,sizeof(b));
	return 0;
}
