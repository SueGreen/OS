
//
// Created by susan on 9/26/2018.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <memory.h>
#include <sys/signal.h>
#include <wait.h>

int my_pipe[2];
char buff[100];

int main() {
    pipe(my_pipe);
    int status;
    printf("Im gonna create the first child\n");
    pid_t child_one_pid = fork();
    if (child_one_pid == -1) { // couldn't fork
        return -1;
    } else if (child_one_pid == 0) { // the first child
        sleep(2);
        pid_t parent;
        read(my_pipe[0], &parent, sizeof(pid_t));
        kill(parent, SIGSTOP);
    } else { //parent
        printf("Im gonna create the second child\n");
        pid_t child_two_pid = fork();
        if (child_two_pid != 0) {
            write(my_pipe[1], &child_two_pid, sizeof(pid_t));
            printf("The second child is gonna stop\n");
            waitpid(child_two_pid, &status, 0);
            printf("The second child stopped\n");
        } else { while (1); }
    }
    return 0;
}


