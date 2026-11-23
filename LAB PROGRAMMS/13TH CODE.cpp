
#include <stdio.h>

void firstfit(int mp[], int p[], int m, int n)
{
    int allocation[20];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[j] >= p[i]) {
                allocation[i] = j;
                mp[j] -= p[i];
                break;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (allocation[i] != -1)
            printf("\nProcess %d allocated to partition %d",
                   i + 1, allocation[i] + 1);
        else
            printf("\nProcess %d must wait", i + 1);
    }
}

void bestfit(int mp[], int p[], int m, int n)
{
    int allocation[20];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++) {
        int best = -1;

        for (int j = 0; j < n; j++) {
            if (mp[j] >= p[i]) {
                if (best == -1 || mp[j] < mp[best])
                    best = j;
            }
        }

        if (best != -1) {
            allocation[i] = best;
            mp[best] -= p[i];
        }
    }

    for (int i = 0; i < m; i++) {
        if (allocation[i] != -1)
            printf("\nProcess %d allocated to partition %d",
                   i + 1, allocation[i] + 1);
        else
            printf("\nProcess %d must wait", i + 1);
    }
}

void worstfit(int mp[], int p[], int m, int n)
{
    int allocation[20];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++) {
        int worst = -1;

        for (int j = 0; j < n; j++) {
            if (mp[j] >= p[i]) {
                if (worst == -1 || mp[j] > mp[worst])
                    worst = j;
            }
        }

        if (worst != -1) {
            allocation[i] = worst;
            mp[worst] -= p[i];
        }
    }

    for (int i = 0; i < m; i++) {
        if (allocation[i] != -1)
            printf("\nProcess %d allocated to partition %d",
                   i + 1, allocation[i] + 1);
        else
            printf("\nProcess %d must wait", i + 1);
    }
}

int main(void)
{
    int m, n, mp[20], p[20], ch;

    printf("Number of memory partitions: ");
    scanf("%d", &n);

    printf("Number of processes: ");
    scanf("%d", &m);

    if (n <= 0 || n > 20 || m <= 0 || m > 20) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter the memory partitions:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &mp[i]);

    printf("Enter process sizes:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &p[i]);

    printf("\n1. First Fit\n2. Best Fit\n3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            firstfit(mp, p, m, n);
            break;

        case 2:
            bestfit(mp, p, m, n);
            break;

        case 3:
            worstfit(mp, p, m, n);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

