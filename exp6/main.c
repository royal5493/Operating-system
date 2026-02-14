#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int burst[10], remaining[10], priority[10];
    int waiting[10], turnaround[10], finish[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Enter Priority for P%d: ", i + 1);
        scanf("%d", &priority[i]);
        remaining[i] = burst[i];
    }

    while (completed < n) {
        int idx = -1, minPriority = 9999;

        for (i = 0; i < n; i++) {
            if (remaining[i] > 0 && priority[i] < minPriority) {
                minPriority = priority[i];
                idx = i;
            }
        }

        remaining[idx]--;
        time++;

        if (remaining[idx] == 0) {
            completed++;
            finish[idx] = time;
        }
    }

    for (i = 0; i < n; i++) {
        turnaround[i] = finish[i];
        waiting[i] = turnaround[i] - burst[i];
    }

    printf("\nPID\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, burst[i], priority[i], waiting[i], turnaround[i]);

    return 0;
}
