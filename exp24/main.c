#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd;
    char buf[50];

    fd = open("test.txt", O_RDONLY);
    read(fd, buf, sizeof(buf));
    write(1, buf, sizeof(buf));
    close(fd);

    return 0;
}
