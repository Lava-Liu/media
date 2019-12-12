#include <stdio.h>
int main(void)
{
   FILE *fp = fopen("a.txt","r");
   int i;
   for(i=0;i<10;i++)
   {
	   printf("%c",fgetc(fp));
   }
   printf("\n");
   for(i=0;i<5;i++)
   {
		ungetc('A',fp);

   }
   for(i=0;i<10;i++)
   {
	   printf("%c",fgetc(fp));
   }
   printf("\n");

   fclose(fp);
   return 0;
}
