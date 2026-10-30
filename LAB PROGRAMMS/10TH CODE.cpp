
#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hPipe = CreateNamedPipeA(
        "\\\\.\\pipe\\MyPipe",
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_MESSAGE | PIPE_WAIT,
        1,
        512,
        512,
        0,
        NULL
    );

    if (hPipe == INVALID_HANDLE_VALUE) {
        printf("Failed: %lu\n", GetLastError());
        return 1;
    }

    printf("Message pipe created.\n");

    

    CloseHandle(hPipe);

    return 0;
}

