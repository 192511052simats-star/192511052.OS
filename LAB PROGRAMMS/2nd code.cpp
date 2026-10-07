#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int f1, f2;
    char ch;

    f1 = open("source.txt", O_RDONLY);
    f2 = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while (read(f1, &ch, 1))
    {
        write(f2, &ch, 1);
    }

    close(f1);
    close(f2);

    printf("File copied successfully");

    return 0;
}
