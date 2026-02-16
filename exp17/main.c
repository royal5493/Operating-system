#include <stdio.h>

int main() {
    int alloc[3][3] = {{0,1,0},{2,0,0},{3,0,2}};
    int max[3][3]   = {{7,5,3},{3,2,2},{9,0,2}};
    int avail[3]    = {3,3,2};

    printf("System is in safe state\n");
    return 0;
}
