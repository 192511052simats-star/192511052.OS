
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char data[] = "Hello, UNIX file system calls!\n";
    char buffer[100] = {0};
    int fd;

    // Create and write to file
    fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd < 0) {
        perror("File opening failed");
        return 1;
    }

    write(fd, data, sizeof(data) - 1);
    close(fd);

    printf("File created and written.\n");

    // Open and read the file
    fd = open("test.txt", O_RDONLY);

    if (fd < 0) {
        perror("File opening failed");
        return 1;
    }

    read(fd, buffer, sizeof(buffer) - 1);
    close(fd);

    printf("File content: %s", buffer);

    // Delete the file
    unlink("test.txt");

    printf("File deleted.\n");

    return 0;
}

