
//
// Created by susan on 9/26/2018.
//

#include <sys/param.h>
#include <unistd.h>
#include <sys/signal.h>
#include <stdio.h>
#include <stdlib.h>

void *handle_sigstop(int num) {
    printf("Caught sigstop! signal number is %d\n", num);
}

void *handle_sigusr1(int num) {
    printf("Caught sigusr1! signal number is %d\n", num);
}

void *handle_sigkill(int num) {
    printf("Caught sigkill! signal number is %d\n", num);
}

int main() {
    signal(SIGSTOP, handle_sigstop);
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGKILL, handle_sigkill);

    while (1) {
        sleep(1);
    }
    return 0;
}

