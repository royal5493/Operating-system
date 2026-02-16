#include <stdio.h>

int main() {
    int frames, pages, i, j, k, fault = 0;
    int f[10], p[20];

    printf("Enter frames and pages: ");
    scanf("%d %d", &frames, &pages);

    for (i = 0; i < pages; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < frames; i++)
        f[i] = -1;

    for (i = 0; i < pages; i++) {
        int hit = 0;
        for (j = 0; j < frames; j++)
            if (f[j] == p[i]) hit = 1;

        if (!hit) {
            int idx = -1, far = i + 1;
            for (j = 0; j < frames; j++) {
                for (k = i + 1; k < pages; k++)
                    if (f[j] == p[k]) break;

                if (k > far) {
                    far = k;
                    idx = j;
                }
                if (k == pages) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) idx = 0;
            f[idx] = p[i];
            fault++;
        }
    }

    printf("Total Page Faults = %d\n", fault);
    return 0;
}
