#include <stdio.h>

int main() {
    int frames, pages, i, j, time[10], f[10], p[20], fault = 0, t = 0;

    printf("Enter frames and pages: ");
    scanf("%d %d", &frames, &pages);

    for (i = 0; i < pages; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < frames; i++)
        f[i] = -1;

    for (i = 0; i < pages; i++) {
        int hit = 0;
        for (j = 0; j < frames; j++) {
            if (f[j] == p[i]) {
                hit = 1;
                time[j] = ++t;
            }
        }

        if (!hit) {
            int lru = 0;
            for (j = 1; j < frames; j++)
                if (time[j] < time[lru]) lru = j;

            f[lru] = p[i];
            time[lru] = ++t;
            fault++;
        }
    }

    printf("Total Page Faults = %d\n", fault);
    return 0;
}
