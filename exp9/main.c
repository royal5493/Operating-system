#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hMap;
    char *data;

    hMap = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        256,
        "MySharedMemory"
    );

    data = (char *)MapViewOfFile(
        hMap,
        FILE_MAP_ALL_ACCESS,
        0, 0, 256
    );

    sprintf(data, "Hello from Process A");

    printf("Data written to shared memory\n");

    UnmapViewOfFile(data);
    CloseHandle(hMap);

    return 0;
}
