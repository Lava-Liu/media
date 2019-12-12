#include "rc.h"
#include <stdio.h>

void main (){
int i,j,k,n;
static int a[100][100];
for(i=0;i<10;i++)
	for(j=0;j<10;j++)
{
	scanf("%d",&a[i][j]);
	/*gets(a[i][j]);*/
	if  (a[i][j]==0)
		continue;
}
for(k=0;k<100;k++)
for(n=0;n<100;n++){
printf ("%d linenember=%d\n",a[k][n],n);

}





}
