#include <stdio.h>
int main(void)
{
  printf("\033[1H\033[2J");
   fflush(stdout);
   return 0;
}
