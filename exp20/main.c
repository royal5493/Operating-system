#include <stdio.h>
#include <windows.h>

HANDLE rw_mutex;

DWORD WINAPI reader(LPVOID p) {
    WaitForSingleObject(rw_mutex, INFINITE);
    printf("Reader is reading\n");
    ReleaseSemaphore(rw_mutex, 1, NULL);
    return 0;
}

DWORD WINAPI writer(LPVOID p) {
    WaitForSingleObject(rw_mutex, INFINITE);
    printf("Writer is writing\n");
    ReleaseSemaphore(rw_mutex, 1, NULL);
    return 0;
}

int main() {
    rw_mutex = CreateSemaphore(NULL, 1, 1, NULL);
    CreateThread(NULL, 0, reader, NULL, 0, NULL);
    CreateThread(NULL, 0, writer, NULL, 0, NULL);
    Sleep(1000);
    return 0;
}
