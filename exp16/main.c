#include <stdio.h>

struct emp {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct emp e;

    fp = fopen("emp.dat", "wb");

    printf("Enter ID, Name, Salary: ");
    scanf("%d %s %f", &e.id, e.name, &e.salary);

    fwrite(&e, sizeof(e), 1, fp);
    fclose(fp);

    fp = fopen("emp.dat", "rb");
    fread(&e, sizeof(e), 1, fp);

    printf("ID: %d Name: %s Salary: %.2f\n", e.id, e.name, e.salary);
    fclose(fp);
    return 0;
}
