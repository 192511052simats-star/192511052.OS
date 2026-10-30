
#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hMap = CreateFileMappingA(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        4096,
        "MySharedMemory"
    );

    if (hMap == NULL) {
        printf("Failed: %lu\n", GetLastError());
        return 1;
    }

    char *ptr = (char *)MapViewOfFile(
        hMap,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        4096
    );

    if (ptr == NULL) {
        printf("Mapping failed: %lu\n", GetLastError());
        CloseHandle(hMap);
        return 1;
    }

    printf("Shared memory created and mapped.\n");

    UnmapViewOfFile(ptr);
    CloseHandle(hMap);

    return 0;
}

