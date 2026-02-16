#include <stdio.h>

int main() {
    int start, len, i;

    printf("Enter starting block: ");
    scanf("%d", &start);
    printf("Enter length of file: ");
    scanf("%d", &len);

    printf("File blocks:\n");
    for (i = start; i < start + len; i++)
        printf("%d ", i);

    return 0;
}
