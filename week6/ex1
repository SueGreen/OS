#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <memory.h>

int my_pipe[2];
char *s1 = "First string";
char buff[100];

int main() {
    pipe(my_pipe);
    write(my_pipe[1], s1, strlen(s1));
    read(my_pipe[0], buff, sizeof(buff));
    printf("%s", buff);
    return 0;
}

