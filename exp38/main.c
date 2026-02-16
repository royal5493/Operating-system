#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, total = 0, i;
    int req[20];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    for (i = 0; i < n; i++)
        total += abs(req[i] - head);

    printf("Total Head Movement = %d\n", total);
    return 0;
}
