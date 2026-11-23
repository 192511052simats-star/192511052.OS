
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char buffer[100] = {0};
    int fd, n;

    // Create and write to a file
    fd = open("file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("Error creating file");
        return 1;
    }

    write(fd, "Hello World\n", 12);
    close(fd);

    printf("File created and written.\n");

    // Append more data to the file
    fd = open("file.txt", O_WRONLY | O_APPEND);

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    write(fd, "Appended Line\n", 14);
    close(fd);

    printf("Data appended.\n");

    // Read the file
    fd = open("file.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error reading file");
        return 1;
    }

    n = read(fd, buffer, sizeof(buffer) - 1);

    if (n >= 0)
        buffer[n] = '\0';
    else
    {
        perror("Read error");
        close(fd);
        return 1;
    }

    close(fd);

    printf("File contents:\n%s", buffer);

    // Rename the file
    if (rename("file.txt", "renamed.txt") == 0)
        printf("File renamed.\n");
    else
        perror("Rename failed");

    // Delete the file
    if (unlink("renamed.txt") == 0)
        printf("File deleted.\n");
    else
        perror("Delete failed");

    return 0;
}

