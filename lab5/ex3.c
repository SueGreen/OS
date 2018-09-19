#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define max_size 15
int buff[max_size];
int size = 0;
int rest = 0;

void* master_function(void* var) {
    while (1) {
        printf("Hi Im a master\n");
        if (size == 0) {
            rest = 1;
            while (rest) {}
        } else {
            size--;
            if (size == max_size - 1) {
                rest = 1;
                while (rest) {}
            }
        }
    }
}

void* slave_function(void* var) {
    int u = 0;
    while (1) {
        printf("Hi Im a slave\n");
        if (size == max_size) {
            rest = 1;
            while (rest) {}
        } else {
            size++;
            buff[size - 1] = u;
            if (size == 1)
                rest = 0;
        }
        u++;
    }
}

int main() {
    pthread_t master;
    pthread_t slave;
    size = 0;
    rest = 0;
    pthread_create(&slave, NULL, master_function, NULL);
    pthread_create(&master, NULL, slave_function, NULL);
    pthread_join(master, NULL);
    pthread_join(slave, NULL);
    return 0;
}  
