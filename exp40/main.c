#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat s;
    stat("file.txt", &s);

    printf("Permissions: %o\n", s.st_mode & 0777);
    return 0;
}
