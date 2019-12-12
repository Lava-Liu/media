#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>

int main(int argc,char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage access [filename]\n");
        exit(1);
    }
	if(access(argv[1],R_OK)==0)
	{
		printf("you have read permission\n");
	}else
	{
		printf("you can't read this file\n");
	}
	if(access(argv[1],W_OK)==0)
	{
		printf("you have write permission\n");
	}else
	{
		printf("you can't write this file\n");
	}
	if(access(argv[1],X_OK)==0)
	{
		printf("you have execute permission\n");
	}else
	{
		printf("you can't exec this file\n");
	}
	if(access(argv[1],F_OK)==0)
	{
		printf("the file is exist\n");
	}else
	{
		printf("the dile is not exist\n");
	}


    return 0;
}

