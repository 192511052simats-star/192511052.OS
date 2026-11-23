
#include <stdio.h>

int main()
{
    int frames, n, i, j;
    int pages[50], frame[10];
    int front = 0;
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

    // Initialize frames
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");
    printf("--------------------------------\n");

    for (i = 0; i < n; i++)
    {
        int found = 0;

        for (j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (found)
            hits++;
        else
        {
            frame[front] = pages[i];
            front = (front + 1) % frames;
            faults++;
        }

        printf("%d\t", pages[i]);

        for (j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        printf("\t\t%s\n", found ? "Hit" : "Page Fault");
    }

    printf("--------------------------------\n");
    printf("Total Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", hits);
    printf("Page Fault Rate = %.2f%%\n", (float)faults / n * 100);
    printf("Hit Rate = %.2f%%\n", (float)hits / n * 100);

    return 0;
}

