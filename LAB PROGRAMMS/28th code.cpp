
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char line[256];
    FILE *fp;

    if (argc != 3)
    {
        printf("Usage: %s <pattern> <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[2], "r");

    if (fp == NULL)
    {
        perror("fopen failed");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, argv[1]) != NULL)
        {
            printf("%s", line);
        }
    }

    fclose(fp);

    return 0;
}

