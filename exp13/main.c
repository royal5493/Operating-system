#include <stdio.h>

int main() {
    int blocks[5], process[5], n, m, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < m; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    for (i = 0; i < n; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &process[i]);
    }

    printf("\nProcess No\tProcess Size\tBlock Allocated\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (blocks[j] >= process[i]) {
                printf("%d\t\t%d\t\t%d\n", i + 1, process[i], j + 1);
                blocks[j] -= process[i];
                break;
            }
        }
    }
    return 0;
}
