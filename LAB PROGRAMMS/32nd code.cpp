
#include <stdio.h>

int main()
{
    int frames, n, i, j, k;
    int pages[50], stack[10];
    int count = 0;
    int faults = 0, hits = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages in the reference string: ");
    scanf("%d", &n);

    if (frames < 1 || frames > 10 || n < 1 || n > 50)
    {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("\nPage\tStack (MRU -> LRU)\tStatus\n");
    printf("--------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        int pos = -1;

        // Search for page in stack
        for (j = 0; j < count; j++)
        {
            if (stack[j] == pages[i])
            {
                pos = j;
                break;
            }
        }

        if (pos != -1)
        {
            hits++;

            // Move page to top
            for (k = pos; k > 0; k--)
                stack[k] = stack[k - 1];

            stack[0] = pages[i];
        }
        else
        {
            faults++;

            if (count < frames)
                count++;

            // Remove least recently used page
            for (k = count - 1; k > 0; k--)
                stack[k] = stack[k - 1];

            stack[0] = pages[i];
        }

        printf("%d\t", pages[i]);

        for (j = 0; j < count; j++)
            printf("%d ", stack[j]);

        for (j = count; j < frames; j++)
            printf("- ");

        printf("\t\t%s\n", pos != -1 ? "Hit" : "Page Fault");
    }

    printf("--------------------------------------------\n");
    printf("Total Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", hits);
    printf("Page Fault Rate = %.2f%%\n", (float)faults / n * 100);
    printf("Hit Rate = %.2f%%\n", (float)hits / n * 100);

    return 0;
}

