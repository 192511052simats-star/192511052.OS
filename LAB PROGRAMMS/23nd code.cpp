
#include <stdio.h>
#define MAX 20

void worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[MAX];
    int tempBlockSize[MAX];
    int i, j;

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < m; i++)
        tempBlockSize[i] = blockSize[i];

    for (i = 0; i < n; i++)
    {
        int worstIdx = -1;

        for (j = 0; j < m; j++)
        {
            if (tempBlockSize[j] >= processSize[i])
            {
                if (worstIdx == -1 ||
                    tempBlockSize[j] > tempBlockSize[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            tempBlockSize[worstIdx] -= processSize[i];
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
                   tempBlockSize[allocation[i]]);
        }
        else
        {
            printf("Not Allocated\t-\n");
        }
    }
}

int main()
{
    int m, n, i;
    int blockSize[MAX], processSize[MAX];

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
    }

    worstFit(blockSize, m, processSize, n);

    return 0;
}

