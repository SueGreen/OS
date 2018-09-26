//
// Created by susan on 9/26/2018.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <memory.h>

int my_pipe[2];
char *s1 = "First string";
char buff[100];

int main() {
    pipe(my_pipe);
    pid_t child_pid = fork();
    if (child_pid == -1) {
        return -1;
    } else if (child_pid == 0) {
        write(my_pipe[1], s1, strlen(s1));
    } else {
        read(my_pipe[0], buff, sizeof(buff));
        printf("%s", buff);
    }
    return 0;
}
