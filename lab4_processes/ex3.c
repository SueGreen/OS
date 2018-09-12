//
// Created by Сюзанна on 12.09.2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void get_command(char *command) {
    fgets(command, sizeof(command), stdin);
}

int main(void) {
    char next_command[32];
    while (1) {
        printf("> ");
        get_command(next_command);
        system(next_command);
    }
}





