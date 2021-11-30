#include <iostream>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define SIZE 1024
int main() {
    int fd = open("myfi.txt", O_RDWR);
    // int ret = ftruncate(fd,20);
    char* ptr = (char*)mmap(nullptr, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    const char* buf = "jianjielong\0";
    memcpy(ptr, buf, sizeof buf);
    printf("%s\n", ptr);
    sleep(20);
    const char* buf2 = "heiheihei";
    memcpy(ptr, buf2, sizeof buf2);
    munmap(ptr, SIZE);
    close(fd);
}