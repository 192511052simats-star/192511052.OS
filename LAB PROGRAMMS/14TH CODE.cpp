
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void copy()
{
    const char *sourcefile = "sasi.txt";
    const char *destination_file = "sk.txt";

    int source_fd = open(sourcefile, O_RDONLY);

    if (source_fd < 0) {
        perror("Source file error");
        return;
    }

    int dest_fd = open(destination_file,
                       O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (dest_fd < 0) {
        perror("Destination file error");
        close(source_fd);
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    while ((bytesRead = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        ssize_t totalWritten = 0;

        while (totalWritten < bytesRead) {
            bytesWritten = write(dest_fd,
                                 buffer + totalWritten,
                                 bytesRead - totalWritten);

            if (bytesWritten < 0) {
                perror("Write error");
                close(source_fd);
                close(dest_fd);
                return;
            }

            totalWritten += bytesWritten;
        }
    }

    if (bytesRead < 0)
        perror("Read error");
    else
        printf("File copied successfully.\n");

    close(source_fd);
    close(dest_fd);
}

void create()
{
    FILE *fp;

    fp = fopen("sasi.txt", "w");

    if (fp == NULL) {
        perror("File creation failed");
        return;
    }

    printf("File created successfully.\n");
    fclose(fp);
}

int main(void)
{
    int n;

    printf("1. Create\t2. Copy\t3. Delete\n");
    printf("Enter your choice: ");
    scanf("%d", &n);

    switch (n) {
        case 1:
            create();
            break;

        case 2:
            copy();
            break;

        case 3:
            if (remove("sasi.txt") == 0)
                printf("Deleted successfully.\n");
            else
                perror("Delete failed");
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

