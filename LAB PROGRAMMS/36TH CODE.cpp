
#include <stdio.h>
#define MAX 100

int main(void)
{
    int disk[MAX] = {0};
    int next[MAX];
    int n, i, blk, start = -1, prev = -1;

    printf("Enter number of blocks needed: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of blocks.\n");
        return 1;
    }

    printf("Enter the block numbers in order: ");

    for (i = 0; i < n; i++) {
        scanf("%d", &blk);

        if (blk < 0 || blk >= MAX || disk[blk] == 1) {
            printf("Block %d is invalid or already allocated.\n", blk);
            return 1;
        }

        disk[blk] = 1;
        next[blk] = -1;

        if (start == -1)
            start = blk;
        else
            next[prev] = blk;

        prev = blk;
    }

    printf("\nStart block : %d\n", start);
    printf("End block : %d\n", prev);

    printf("Chain : ");
    for (blk = start; blk != -1; blk = next[blk])
        printf("%d -> ", blk);

    printf("NULL\n");

    return 0;
}

