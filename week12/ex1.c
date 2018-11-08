#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define string_length 20

int main() {
    unsigned char buffer[string_length];
    int fd = open("/dev/random", O_RDONLY);
    if (fd < 0) {
        return -1;
    }
    int sequence = read(fd, buffer, string_length);
    if (sequence < 0) {
        return -1;
    }
    close(fd);
    FILE *my_file = fopen("ex1.txt", "w");
    fprintf(my_file, "%s", buffer);
    fclose(my_file);
    return 0;
}
