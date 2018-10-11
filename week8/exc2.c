#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <zconf.h>

int main(){
    int bytes = (1024*1024);
    char* ptr;
    for (int i = 0; i < 10; i++){
        ptr = (char*) malloc(10 * bytes);
        memset(ptr, '0', 10*bytes);
        printf("%d", i);
        sleep(1);
    }
    return 0;
}
