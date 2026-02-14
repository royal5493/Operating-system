#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE src, dest;
    char buffer[1024];
    DWORD bytesRead, bytesWritten;

    // CHANGE USERNAME AND FILENAME
    char sourcePath[] =
        "C:\\Users\\jaswa\\Downloads\\source.txt";

    char destPath[] =
        "C:\\Users\\jaswa\\Desktop\\bye.txt";

    src = CreateFile(
        sourcePath,
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (src == INVALID_HANDLE_VALUE) {
        printf("Error opening source file (%lu)\n", GetLastError());
        return 1;
    }

    dest = CreateFile(
        destPath,
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (dest == INVALID_HANDLE_VALUE) {
        printf("Error creating destination file (%lu)\n", GetLastError());
        CloseHandle(src);
        return 1;
    }

    while (ReadFile(src, buffer, sizeof(buffer), &bytesRead, NULL) && bytesRead > 0) {
        WriteFile(dest, buffer, bytesRead, &bytesWritten, NULL);
    }

    printf("File copied successfully.\n");

    CloseHandle(src);
    CloseHandle(dest);

    return 0;
}
