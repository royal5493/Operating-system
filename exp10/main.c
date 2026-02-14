#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hSlot;
    DWORD written;
    char msg[] = "Hello via Message Queue";

    hSlot = CreateFile(
        "\\\\.\\mailslot\\MyMailSlot",
        GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    WriteFile(hSlot, msg, sizeof(msg), &written, NULL);
    CloseHandle(hSlot);

    return 0;
}
