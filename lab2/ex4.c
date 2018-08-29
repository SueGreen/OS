//
// Created by Сюзанна on 29.08.2018.
//

#include <stdio.h>

int main(){
    printf("Enter two integers\n");
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("a = %d, ", a);
    printf("b = %d\n", b);
    swap(&a, &b);
    printf("now a = %d, ", a);
    printf("b = %d\n", b);

    return 0;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

