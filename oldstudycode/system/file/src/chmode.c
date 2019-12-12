#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
int dex_oct(int val)

{
	if( val > 7777)
		return -1;
	int a = val/1000;
	
	int b = val/100%10;
	if(b > 7)
		return -1;
	int c = val/10%10;
	if(c > 7)
		return -1;
	int d = val%10;
	if(d > 7)
		return -1;
	return a*8*8*8 +b*8*8+c*8+b;
}

int main(int argc,char* argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"%s [filename]\n",argv[0]);
		exit(1);
	}
	int mode;
	if((mode=dex_oct(atoi(argv[2])))<0)
	{
		fprintf(stderr,"mode unknow!\n");
		exit(1);

	}
	if(chmod(argv[1],mode)<0)
	{
		fprintf(stderr,"chmod%s\n",strerror(errno));
		exit(1);

	}
	return 0;
}

