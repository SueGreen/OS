#include <stdio.h>

//
// Created by Сюзанна on 05.09.2018.
//
void swap(int *a, int *b);

void bubble_sort(int*a, int length) {
    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length-i-1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    printf("%s", "Enter the length of your array");
    int c;
    scanf("%d", &c);
    int arr[c];
    for (int i = 0; i < c; i++){
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, c);
    for (int j = 0; j < c; ++j) {
        printf("%d", arr[j]);
    }
}

