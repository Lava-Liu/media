
#include <stdio.h>

enum mobile {iphone = 10,HTC, samsung};




int main(void)
{
	enum mobile m;
    m = iphone;
    m = HTC;
    printf("m:%c",m);	
	printf("iphone: %d\n",iphone);
	printf("HTC: %d\n",HTC);
	printf("samsung: %d\n",samsung);
	//iphone =10 ; //error!
	return 0;





}
