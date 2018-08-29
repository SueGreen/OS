//
// Created by Сюзанна on 29.08.2018.
//

#include <stdio.h>

int main() {
    printf("Enter the height: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++, printf("\n")) {
        for (int j = 0; j < n - i - 1; ++j, printf("%c", ' '));
        for (int k = 0; k < (i << 1) + 1; ++k, printf("%c", '*'));
        for (int j = 0; j < n - i - 1; ++j, printf("%c", ' '));
    }
    return 0;
}
