#include <sys/param.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

//
// Created by susan on 9/26/2018.
//

int main() {
    pid_t child_pid = fork();
    if (child_pid == -1) {
        return -1;
    } else if (child_pid == 0) {
        while (1) {
            printf("I'm alive!\n");
            sleep(1);
        }
    } else {
        sleep(10);
        kill(child_pid, SIGTERM);
    }
    return 0;
}
