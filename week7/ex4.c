//
// Created by susan on 10/3/2018.
//

#include <endian.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

int flag = 0;

void *my_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        flag = 1;
        return malloc(size);
    }
    if (size == 0) {
        flag = 1;
        free(ptr);
        return NULL;
    }
    void *ptr_new;
    ptr_new = malloc(size);
    ptr_new = memcpy(ptr_new, (int *) ptr, size);
    free(ptr);
    return ptr_new;
}

int main() {
    int n1 = 24;
    int *p = malloc(n1 * sizeof(int));
    printf("Initial array: ");
    for (int i = 0; i < n1; ++i) {
        p[i] = i;
        printf("%d ", p[i]);
    }
    printf("\n");
    int n2 = 10;
    printf("Reallocating memory for size = %d\n", n2);
    p = my_realloc(p, n2 * sizeof(int));
    if (!flag) {
        for (int i = 0; i < n2; ++i) {
            printf("%d ", p[i]);
        }
    } else printf("NULL or size = 0");
}

