#include <stdio.h>

int main() {
    int block[10], process[10], m, n;
    int i, j, worst, allocation[10];

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < m; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    for (i = 0; i < n; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    for (i = 0; i < n; i++) {
        worst = -1;
        for (j = 0; j < m; j++) {
            if (block[j] >= process[i]) {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }
        if (worst != -1) {
            allocation[i] = worst;
            block[worst] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%s\n", i + 1, process[i],
               allocation[i] != -1 ? "Allocated" : "Not Allocated");

    return 0;
}
