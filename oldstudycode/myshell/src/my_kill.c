#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
int main(int argc,char *argv[])
{
	if(argc < 2)
		  {
			  fprintf(stderr,"usage: %s  [pid]\n",argv[0]);
			  exit(1);
		  }
	if(strcmp(argv[1],"-9"))
      {
		  if(argc < 2)
		  {
			  fprintf(stderr,"usage: %s -9 [pid]\n",argv[0]);
			  exit(1);
		  }
		  int i;
		  for(i=2;i<argc;i++)
		  {
			  kill(atoi(argv[i]),9);
		  }
	  }
	else if(argc < 2)
	{
		fprintf(stderr,"usage: %s  [pid]\n",argv[0]);
		exit(1);
	}else
	{
		int i;
		
		  for(i=2;i<argc;i++)
		  {
			  kill(atoi(argv[i]),2);
		  }
	}
	
	return 0;
}
