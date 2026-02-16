#include <stdio.h>

int main() {
    int block[10], process[10], m, n, i, j;

    printf("Enter blocks and processes: ");
    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++)
        scanf("%d", &block[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &process[i]);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (block[j] >= process[i]) {
                block[j] -= process[i];
                printf("Process %d allocated to Block %d\n", i + 1, j + 1);
                break;
            }
        }
    }
    return 0;
}
