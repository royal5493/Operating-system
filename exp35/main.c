#include <stdio.h>

int main() {
    int index[10], n, i;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &index[i]);

    printf("Indexed allocation:\n");
    for (i = 0; i < n; i++)
        printf("Index[%d] -> Block %d\n", i, index[i]);

    return 0;
}
