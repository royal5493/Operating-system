#include <windows.h>
#include <stdio.h>

  int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    DWORD parentPID = GetCurrentProcessId();

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create a child process (cmd.exe)
    if (!CreateProcess(
        "C:\\Windows\\System32\\cmd.exe",
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    )) {
        printf("CreateProcess failed (%lu)\n", GetLastError());
        return 1;
    }

    printf("Parent Process ID : %lu\n", parentPID);
    printf("Child Process ID  : %lu\n", pi.dwProcessId);

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
