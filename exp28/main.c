#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[100], word[20];

    printf("Enter word to search: ");
    scanf("%s", word);

    fp = fopen("file.txt", "r");
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, word))
            printf("%s", line);
    }
    fclose(fp);
    return 0;
}
