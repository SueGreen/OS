#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <memory.h>

int main(void) {
    int in_file = open("ex1.txt", O_CREAT | O_RDWR, 0);
    char replace_string[] = "This is a nice day";
    struct stat file_stat;
    stat("ex1.txt", &file_stat);
    int file_size = (int) file_stat.st_size;
    ftruncate(in_file, strlen(replace_string));
    char *map = mmap(0, (size_t) file_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED, in_file, 0);
    strcpy(map, "This is a nice day");
    close(in_file);
    return 0;
}
