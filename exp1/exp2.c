
#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE src, dest;
    char buffer[1024];
    DWORD bytesRead, bytesWritten;

    src = CreateFile(
        "source.txt",
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (src == INVALID_HANDLE_VALUE) {
        printf("Cannot open source file\n");
        return 1;
    }

    dest = CreateFile(
        "destination.txt",
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (dest == INVALID_HANDLE_VALUE) {
        printf("Cannot create destination file\n");
        CloseHandle(src);
        return 1;
    }

    while (ReadFile(src, buffer, sizeof(buffer), &bytesRead, NULL) && bytesRead > 0) {
        WriteFile(dest, buffer, bytesRead, &bytesWritten, NULL);
    }

    printf("File copied successfully\n");

    CloseHandle(src);
    CloseHandle(dest);

    return 0;
}
