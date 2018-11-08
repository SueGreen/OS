//
// Created by susan on 11/8/2018.
//

#include <stdio.h>
#include <malloc.h>
#include <fcntl.h>
#include <memory.h>
#include <unistd.h>

#define BUF_SIZE 512

int main(int argc, char *argv[]) {
    if (argc < 1) {
        return -1;
    }
    const char *f_mode;
    char buffer[BUF_SIZE];
    int files_num = argc - 1;
    int flag = 0;
    if (strcmp("-a", argv[1]) == 0) {
        files_num = files_num - 1;
        flag = 1;
    }
    if (flag != 0) {
        f_mode = "a";
    } else {
        f_mode = "w";
    }
    int *files;
    files = malloc(sizeof(char) * (files_num));
    int j = 0;
    for (int i = argc - files_num; i < argc; i++) {
        if (flag == 0)
            files[j] = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC);
        else
            files[j] = open(argv[i], O_WRONLY | O_APPEND | O_CREAT);
        if (files[j] == -1) {
            files_num = files_num - 1;
        } else {
            j = j + 1;
        }
    }
    size_t string_size = 0;
    while (fgets(buffer, BUF_SIZE, stdin)) {
        printf("%s", buffer);
        string_size = strlen(buffer);
        for (int i = 0; i < files_num; i++)
            write(files[i], buffer, string_size);
    }
    for (int i = 0; i < files_num; i++)
        close(files[i]);
}

