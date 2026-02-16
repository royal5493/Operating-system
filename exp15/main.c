#include <stdio.h>

int main() {
    int users, files, i, j;

    printf("Enter number of users: ");
    scanf("%d", &users);

    for (i = 0; i < users; i++) {
        printf("Enter number of files for user %d: ", i + 1);
        scanf("%d", &files);

        for (j = 0; j < files; j++) {
            char fname[20];
            printf("Enter file name: ");
            scanf("%s", fname);
        }
    }
    return 0;
}
