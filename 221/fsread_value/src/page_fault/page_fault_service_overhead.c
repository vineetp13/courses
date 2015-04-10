#include "page_fault_service_overhead.h"

void induce_major_page_fault(int fdout, size_t len) 
{
    char *dst;
    // mmap the output file
    dst = mmap(0, 4096, PROT_WRITE, MAP_SHARED, fdout, 0);
    assert(dst != (caddr_t)-1);
    
    const char* text = "1234567890";
    memcpy(dst, text, strlen(text));

    munmap(dst, strlen(text));
}

void page_fault_service_overhead()
{
    int fdout;
    struct stat statbuf;
    const char* ofile_n = "test.txt";

    fdout = open(ofile_n, O_RDWR | O_CREAT | O_TRUNC);
    assert(fdout >= 0);

    // Make page-sized file.
    lseek(fdout, 4096, SEEK_SET);
    write(fdout, "", 1);
    lseek(fdout, 0, SEEK_SET);

    PM_COUNT(induce_major_page_fault(fdout, 1),"Page fault cost,"O_STR,1);
    
    close(fdout);

    unlink(ofile_n);
}
