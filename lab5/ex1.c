#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid) {
    printf("I'm a thread %d\n", tid);
    printf("I'm here to say hi %d\n", tid);
    printf("I'm exiting. Bye! %d\n", tid);
    pthread_exit(NULL);
}

pthread_t threads[NUMBER_OF_THREADS];
int status, i;

int first_method(pthread_t threads[]) {
    printf("First method\nFor the second method we need to uncomment the third line in main");
    for (i = 0; i < NUMBER_OF_THREADS; i++) {
        printf("Main function. Creating thread %d\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *) i);
        if (status != 0) {
            printf("Oops. pthread create returned error code %d\n", status);
            exit(-1);
        }
    }
    for (int j = 0; j < NUMBER_OF_THREADS; ++j) {
        pthread_join(threads[i], NULL);
    }
    exit(0);
}

int second_method(pthread_t threads[]) {
    printf("\n\nSecond method\n");
    for (i = 0; i < NUMBER_OF_THREADS; i++) {
        printf("Main function. Creating thread %d\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *) i);
        pthread_join(threads[i], NULL);
        if (status != 0) {
            printf("Oops. pthread create returned error code %d\n", status);
            exit(-1);
        }
    }
    exit(0);
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUMBER_OF_THREADS];
    first_method(&threads);
//    second_method(&threads);
}

