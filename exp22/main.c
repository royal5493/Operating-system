#include <stdio.h>

int main() {
    int block[10], process[10], m, n;
    int i, j, best, allocation[10];

    printf("Enter number of blocks: ");
    scanf("%d", &m);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < m; i++)
        scanf("%d", &block[i]);

    for (i = 0; i < n; i++) {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    for (i = 0; i < n; i++) {
        best = -1;
        for (j = 0; j < m; j++) {
            if (block[j] >= process[i]) {
                if (best == -1 || block[j] < block[best])
                    best = j;
            }
        }
        if (best != -1) {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nProcess\tStatus\n");
    for (i = 0; i < n; i++)
        printf("%d\t%s\n", i + 1,
               allocation[i] != -1 ? "Allocated" : "Not Allocated");

    return 0;
}
