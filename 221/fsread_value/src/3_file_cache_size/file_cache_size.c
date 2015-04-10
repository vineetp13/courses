#include "file_cache_size.h"

#include<stdio.h>

//#include<unistd.h>
//#include<stdlib.h>
//#include<fcntl.h>


#define SIZE_MEASURING 262144
#define FILESIZE 4096
#define MULTIPLE 2

 #define ITERATIONS 1

void gen_files()
{
        for (int i = 0; i < ITERATIONS; ++i)
        {
                int sz = SIZE_MEASURING<<i;
                char buf[256] = {0};
                sprintf(buf, "./generate_rand_file.sh %d.dat %d", ITERATIONS, sz);
                if (0 != system(buf))
                {
                        fprintf(stderr, "[Error] generating file %d.dat\n", sz);
                }
        }
}

void file_cache_size(){
	gen_files();

	char filen[32] = "trial";
	long long filesize = FILESIZE;
	int result;

        for (int i = 0; i < ITERATIONS; ++i)
        {
                int sz = SIZE_MEASURING<<i;
		sprintf(filen, "./%d.dat", ITERATIONS);
		int fd = open(filen, O_RDONLY); 
		if(fd==-1){
		printf("\n Cannot open file \n");
		return ;}

	result = lseek(fd, filesize-1,SEEK_SET);
	if (result == -1){
		printf("cant seek\n");
		close(fd);
		return ;}
	int readbuf[32];

	printf("%lld %s ", filesize, filen);
	PM_COUNT(read(fd,readbuf,1),"File cache access time "O_STR,1);

	filesize *= MULTIPLE;
	close(fd);
	unlink(filen);
}}
