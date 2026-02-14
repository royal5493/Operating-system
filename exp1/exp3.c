
#include <stdio.h>

int main() {
    int n, i;
    int burst[10], waiting[10], turnaround[10];
    int totalWT = 0, totalTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    waiting[0] = 0;

    for (i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
    }

    for (i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        totalWT += waiting[i];
        totalTAT += turnaround[i];
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           (float)totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n",
           (float)totalTAT / n);

    return 0;
}
