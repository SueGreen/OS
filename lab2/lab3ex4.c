//
// Created by Сюзанна on 05.09.2018.
//

#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    while (low < high) {
        int partition_index = partition(arr, low, high);
        if (partition_index - low < high - partition_index) {
            quickSort(arr, low, partition_index - 1);
            low = partition_index + 1;
        } else {
            quickSort(arr, partition_index + 1, high);
            high = partition_index - 1;
        }
    }
}

int main() {
    printf("%s", "Enter the length of your array");
    int c;
    scanf("%d", &c);
    int arr[c];
    printf("%s", "Enter the array");
    for (int i = 0; i < c; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, c - 1);
    for (int j = 0; j < c; ++j) {
        printf("%d", arr[j]);
    }
    return 0;
}