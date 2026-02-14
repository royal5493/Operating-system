#include <stdio.h>

int main() {
    int n, i, j, temp;
    int burst[10], pid[10];
    int waiting[10], turnaround[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &burst[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst[i] > burst[j]) {
                temp = burst[i]; burst[i] = burst[j]; burst[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    waiting[0] = 0;
    for (i = 1; i < n; i++)
        waiting[i] = waiting[i - 1] + burst[i - 1];

    for (i = 0; i < n; i++)
        turnaround[i] = waiting[i] + burst[i];

    printf("\nPID\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n",
               pid[i], burst[i], waiting[i], turnaround[i]);

    return 0;
}
