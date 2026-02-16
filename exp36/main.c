#include <stdio.h>

int main() {
    int n, i, block[10];

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &block[i]);

    printf("Linked allocation:\n");
    for (i = 0; i < n - 1; i++)
        printf("%d -> ", block[i]);
    printf("%d\n", block[n - 1]);

    return 0;
}
