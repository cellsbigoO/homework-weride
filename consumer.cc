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
    int fd = open("myfi.txt", O_RDONLY);
    char* ptr = (char*)mmap(nullptr, SIZE, PROT_READ, MAP_SHARED, fd, 0);
    if(ptr[0] != '\0')
        printf("comsumer:%s\n", ptr);
    munmap(ptr, SIZE);
    close(fd);
}