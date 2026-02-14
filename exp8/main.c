#include <stdio.h>

int main() {
    int n, i, time = 0, quantum;
    int burst[10], remaining[10];
    int waiting[10] = {0}, turnaround[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int done;
    do {
        done = 1;
        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0;
                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    waiting[i] = time - burst[i];
                    remaining[i] = 0;
                }
            }
        }
    } while (!done);

    for (i = 0; i < n; i++)
        turnaround[i] = waiting[i] + burst[i];

    printf("\nPID\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n",
               i + 1, burst[i], waiting[i], turnaround[i]);

    return 0;
}
