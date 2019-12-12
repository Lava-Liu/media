#include <stdio.h>


int main(void)
{
int a = 10;
//const int *pa = &a;
int const *pa = &a;
a = 11;
printf("a = %d\n, a");
*pa = 12;
printf("a = %d\n, a");




return 0;







}
