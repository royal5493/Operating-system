#include <stdio.h>
#include <windows.h>

HANDLE empty, full;

DWORD WINAPI producer(LPVOID p) {
    WaitForSingleObject(empty, INFINITE);
    printf("Producer produced item\n");
    ReleaseSemaphore(full, 1, NULL);
    return 0;
}

DWORD WINAPI consumer(LPVOID p) {
    WaitForSingleObject(full, INFINITE);
    printf("Consumer consumed item\n");
    ReleaseSemaphore(empty, 1, NULL);
    return 0;
}

int main() {
    empty = CreateSemaphore(NULL, 1, 1, NULL);
    full = CreateSemaphore(NULL, 0, 1, NULL);

    CreateThread(NULL, 0, producer, NULL, 0, NULL);
    CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    Sleep(1000);
    return 0;
}
