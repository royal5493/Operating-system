#include <stdio.h>

int main() {
    int frames, pages, i, j, fault = 0, k = 0;
    int f[10], p[20];

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page reference string:\n");
    for (i = 0; i < pages; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < frames; i++)
        f[i] = -1;

    for (i = 0; i < pages; i++) {
        int hit = 0;
        for (j = 0; j < frames; j++)
            if (f[j] == p[i]) hit = 1;

        if (!hit) {
            f[k] = p[i];
            k = (k + 1) % frames;
            fault++;
        }
    }

    printf("Total Page Faults = %d\n", fault);
    return 0;
}
