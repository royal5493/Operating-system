#include <stdio.h>

int main() {
    int n, i, j;
    int burst[10], priority[10], pid[10];
    int waiting[10], turnaround[10];
    int totalWT = 0, totalTAT = 0, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &burst[i]);
        printf("Enter Priority for P%d: ", pid[i]);
        scanf("%d", &priority[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                temp = priority[i]; priority[i] = priority[j]; priority[j] = temp;
                temp = burst[i]; burst[i] = burst[j]; burst[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    waiting[0] = 0;
    for (i = 1; i < n; i++)
        waiting[i] = waiting[i - 1] + burst[i - 1];

    for (i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        totalWT += waiting[i];
        totalTAT += turnaround[i];
    }

    printf("\nPID\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               pid[i], burst[i], priority[i], waiting[i], turnaround[i]);

    printf("\nAverage Waiting Time = %.2f", (float)totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)totalTAT / n);

    return 0;
}
