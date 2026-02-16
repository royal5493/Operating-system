#include <stdio.h>
#include <windows.h>

HANDLE forks[5];

DWORD WINAPI philosopher(LPVOID num) {
    int id = *(int *)num;

    WaitForSingleObject(forks[id], INFINITE);
    WaitForSingleObject(forks[(id + 1) % 5], INFINITE);

    printf("Philosopher %d is eating\n", id);

    ReleaseSemaphore(forks[id], 1, NULL);
    ReleaseSemaphore(forks[(id + 1) % 5], 1, NULL);

    return 0;
}

int main() {
    HANDLE ph[5];
    int i, ids[5];

    for (i = 0; i < 5; i++)
        forks[i] = CreateSemaphore(NULL, 1, 1, NULL);

    for (i = 0; i < 5; i++) {
        ids[i] = i;
        ph[i] = CreateThread(NULL, 0, philosopher, &ids[i], 0, NULL);
    }

    WaitForMultipleObjects(5, ph, TRUE, INFINITE);
    return 0;
}
