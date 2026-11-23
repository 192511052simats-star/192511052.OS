
#include <stdio.h>

#define MAX_BLOCKS 100

int disk[MAX_BLOCKS] = {0};

int main()
{
    int indexBlock, n, i, j, blk;
    int files[MAX_BLOCKS];
    int ok;
    char choice;

    do
    {
        printf("\nEnter the index block: ");
        scanf("%d", &indexBlock);

        if (indexBlock < 0 || indexBlock >= MAX_BLOCKS ||
            disk[indexBlock] == 1)
        {
            printf("Index block is invalid or already allocated.\n");
        }
        else
        {
            printf("Enter the number of blocks needed by the file: ");
            scanf("%d", &n);

            if (n < 1 || n >= MAX_BLOCKS)
            {
                printf("Invalid number of blocks.\n");
            }
            else
            {
                printf("Enter the block numbers: ");

                for (i = 0; i < n; i++)
                    scanf("%d", &files[i]);

                ok = 1;

                // Check block availability
                for (i = 0; i < n; i++)
                {
                    blk = files[i];

                    if (blk < 0 || blk >= MAX_BLOCKS ||
                        disk[blk] == 1 || blk == indexBlock)
                    {
                        printf("Block %d is invalid or already allocated.\n", blk);
                        ok = 0;
                        break;
                    }

                    // Check duplicate blocks
                    for (j = 0; j < i; j++)
                    {
                        if (files[j] == blk)
                        {
                            printf("Block %d was entered twice.\n", blk);
                            ok = 0;
                            break;
                        }
                    }

                    if (!ok)
                        break;
                }

                if (ok)
                {
                    // Allocate index and data blocks
                    disk[indexBlock] = 1;

                    for (i = 0; i < n; i++)
                        disk[files[i]] = 1;

                    printf("\nFile indexed (index block = %d)\n", indexBlock);
                    printf("Index entry -> Data block\n");

                    for (i = 0; i < n; i++)
                        printf("%2d -> %d\n", i, files[i]);
                }
            }
        }

        printf("\nDo you want to enter another file (y/n)? ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

