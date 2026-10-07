#include <stdio.h>

int main()
{
    int n, i, j;
    int pid[10], burst[10], priority[10];
    int temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("\nEnter burst time for P%d: ", pid[i]);
        scanf("%d", &burst[i]);

        printf("Enter priority for P%d: ", pid[i]);
        scanf("%d", &priority[i]);
    }

    /* Sort according to priority */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (priority[i] > priority[j])
            {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    printf("\nProcess\tBurst Time\tPriority\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\n", pid[i], burst[i], priority[i]);
    }

    printf("\nExecution Order: ");

    for (i = 0; i < n; i++)
    {
        printf("P%d", pid[i]);

        if (i < n - 1)
        {
            printf(" -> ");
        }
    }

    printf("\n");

    return 0;
}
