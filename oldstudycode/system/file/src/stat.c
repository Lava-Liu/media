#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"%s [filename\n]",argv[0]);
		exit(1);
	}
	struct stat st;
	memset(&st,0,sizeof(stat));
	if(stat(argv[1],&st) < 0)
	{
		fprintf(stderr,"stat:%s\n",strerror(errno));
		exit(1);
	}
	printf("st_mode: %o\n",st.st_mode);
	printf("st_ino: %ld\n",st.st_ino);
	printf("st_nlink: %d\n",st.st_nlink);
	printf("st_uid: %d\n",st.st_uid);
	printf("st_gid: %d\n",st.st_gid);
	printf("st_size: %ld\n",st.st_size);
	printf("st_atime: %ld\n",st.st_atime);
	printf("st_mtime: %ld\n",st.st_mtime);
	printf("st_ctime: %ld\n",st.st_ctime);
	printf("st_blksize: %ld\n",st.st_blksize);
	printf("st_blocks: %ld\n",st.st_blocks);
	//时间分析
	//ctime函数
	//char *ctime(time_t *time);
	printf("atime:%s",ctime(&st.st_atime));
	printf("mtime:%s",ctime(&st.st_mtime));
	printf("ctime:%s",ctime(&st.st_ctime));
	time_t cur = time(0); 
	printf("time:%s",ctime(&cur));

	printf("st_blocks: %d:%d\n",major(st.st_dev),minor(st.st_dev));
	printf("st_blocks: %d:%d\n",major(st.st_rdev),minor(st.st_rdev));
	printf("st_blocks: %ld\n",st.st_blocks);
	return 0;
}
