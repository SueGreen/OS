#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <memory.h>

int main(void) {
    int file1 = open("ex1.txt", O_RDWR, 0);
    struct stat file1_stat;
    stat("ex1.txt", &file1_stat);
    int file1_size = (int) file1_stat.st_size;
    char *map1 = mmap(0, (size_t) file1_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED, file1, 0);
    int file2 = open("ex1.memcpy.txt", O_CREAT | O_RDWR, 0);
    struct stat file2_stat;
    stat("ex1.txt", &file2_stat);
    int file2_size = (int) file2_stat.st_size;
    
    ftruncate(file2, file1_size);
    char *map2 = mmap(0, (size_t) file1_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED, file2, 0);
    memcpy(map1, map2, (size_t) file1_size);
    close(file1);
    close(file2);
    return 0;
}
