#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

int main() {
    struct stat s;
    stat("test.txt", &s);
    printf("File size: %ld\n", s.st_size);

    DIR *d = opendir(".");
    struct dirent *dir;
    while ((dir = readdir(d)) != NULL)
        printf("%s\n", dir->d_name);

    closedir(d);
    return 0;
}
