#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_THREADS 10

int main(void) {
    pid_t pid;
    int n = 5;
        switch (pid = fork()) {
            case -1:
                exit(1);
            case 0:
                printf("\nHello from child [%d - %d]. My parent's PID is %d\n", getpid(), n, getppid());
                exit(1);
            default:
                printf("\nHello from parent [%d - %d]. My child's PID is %d\n", getpid(), n, pid);
        }
    return 0;
}

