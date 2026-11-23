
#include <stdio.h>
#define MAX 20

int main()
{
    int blockSize[MAX], processSize[MAX], allocation[MAX];
    int m, n, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter sizes of the %d memory blocks:\n", m);

    for (i = 0; i < m; i++)
    {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    printf("Enter sizes of the %d processes:\n", n);

    for (i = 0; i < n; i++)
    {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }

    // First Fit Allocation
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\tFragment Size\n");

    for (i = 0; i < n; i++)
    {
        printf("P%-15d%-16d", i + 1, processSize[i]);

        if (allocation[i] != -1)
        {
            printf("%-16d%d\n",
                   allocation[i] + 1,
                   blockSize[allocation[i]]);
        }
        else
        {
            printf("Not Allocated\t-\n");
        }
    }

    return 0;
}

