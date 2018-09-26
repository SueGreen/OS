#include<stdio.h>
#include<signal.h>
#include <unistd.h>
#include <stdlib.h>

void *handle_sigint(int num) {
    printf("Caught it! signal number is %d\n", num);
    exit(1);
}

int main() {
    signal(SIGINT, handle_sigint);
    while (1) {
        sleep(1);
    }
    return 0;
}
