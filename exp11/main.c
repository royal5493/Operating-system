#include <windows.h>
#include <stdio.h>

DWORD WINAPI threadFunc(LPVOID lpParam) {
    int id = *(int *)lpParam;
    printf("Thread %d is running\n", id);
    return 0;
}

int main() {
    HANDLE threads[2];
    int ids[2] = {1, 2};

    threads[0] = CreateThread(NULL, 0, threadFunc, &ids[0], 0, NULL);
    threads[1] = CreateThread(NULL, 0, threadFunc, &ids[1], 0, NULL);

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    return 0;
}
