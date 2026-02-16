#include <stdio.h>

int main() {
    FILE *fp = fopen("file.txt", "w");
    fprintf(fp, "Hello OS");
    fclose(fp);

    fp = fopen("file.txt", "r");
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    fclose(fp);
    return 0;
}
