
#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *d;
    struct dirent *entry;

    // Open current directory
    d = opendir(".");

    if (d == NULL)
    {
        perror("opendir failed");
        return 1;
    }

    // Read and display directory contents
    while ((entry = readdir(d)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    // Close directory
    closedir(d);

    return 0;
}

