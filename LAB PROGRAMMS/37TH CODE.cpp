
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int req[50], n, head, i, seek, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    if (n <= 0 || n > 50) {
        printf("Invalid number of requests.\n");
        return 1;
    }

    printf("Enter the request queue: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nHead movement:\n");

    for (i = 0; i < n; i++) {
        seek = abs(req[i] - head);
        total += seek;

        printf("%d -> %d (seek = %d)\n", head, req[i], seek);

        head = req[i];
    }

    printf("\nTotal head movement = %d cylinders\n", total);
    printf("Average seek distance = %.2f cylinders\n",
           (float)total / n);

    return 0;
}

