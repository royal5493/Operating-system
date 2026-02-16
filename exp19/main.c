#include <stdio.h>
#include <windows.h>

HANDLE mutex;

DWORD WINAPI task(LPVOID p) {
    WaitForSingleObject(mutex, INFINITE);
    printf("Critical Section Accessed\n");
    ReleaseMutex(mutex);
    return 0;
}

int main() {
    mutex = CreateMutex(NULL, FALSE, NULL);
    CreateThread(NULL, 0, task, NULL, 0, NULL);
    CreateThread(NULL, 0, task, NULL, 0, NULL);
    Sleep(1000);
    return 0;
}
