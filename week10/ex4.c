#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

void output_result(char *file, char *dir, ino_t inode);

int main() {
    DIR *dirp = opendir("./tmp");
    if (dirp == NULL) return 1;
    struct stat sdata;
    struct dirent *dp;
    char file_name[64];
    while ((dp = readdir(dirp)) != NULL) {
        sprintf(file_name, "%s/%s", "./tmp", dp->d_name);
        stat(file_name, &sdata);
        if (sdata.st_nlink > 1 && strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            output_result(dp->d_name, "./tmp", sdata.st_ino);
        }
    }
    return 0;
}

void output_result(char *file, char *dir, ino_t inode) {
    printf("File: %s:\n", file);
    DIR *dirp = opendir(dir);
    if (dirp == NULL) return;
    struct stat sdata;
    struct dirent *dp;
    char file_name[64];
    while ((dp = readdir(dirp)) != NULL) {
        sprintf(file_name, "%s/%s", dir, dp->d_name);
        stat(file_name, &sdata);
        if (sdata.st_ino == inode) printf("%s\n", dp->d_name);
    }
}


