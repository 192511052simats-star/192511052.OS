
#include <stdio.h>

int main()
{
    int disk[50] = {0};
    int start, len, i, r;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter number of records: ");
    scanf("%d", &len);

    // Validate allocation
    if (start < 0 || len <= 0 || start + len > 50)
    {
        printf("Invalid allocation.\n");
        return 1;
    }

    // Allocate blocks
    for (i = start; i < start + len; i++)
    {
        if (disk[i] == 1)
        {
            printf("Block already allocated.\n");
            return 1;
        }

        disk[i] = 1;
    }

    printf("File allocated in blocks %d to %d\n",
           start, start + len - 1);

    printf("Enter record number to access (1-%d): ", len);
    scanf("%d", &r);

    // Validate record number
    if (r < 1 || r > len)
    {
        printf("Invalid record.\n");
        return 1;
    }

    // Sequential access
    for (i = 1; i <= r; i++)
    {
        printf("Reading record %d (block %d)\n",
               i, start + i - 1);
    }

    return 0;
}

