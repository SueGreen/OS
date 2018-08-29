#include <stdio.h>
#include <memory.h>
#include <ctype.h>

//
// Created by Сюзанна on 29.08.2018.
//
int main() {
    printf("Enter a string\n");
    char s[256];
    gets(s);
    int n = strlen(s) - 1;
    for (int i = 0; i <= n / 2; i++) {
        swap(&(s[i]), &(s[n - i]));
    }
    printf("%s", s);
    return 0;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

