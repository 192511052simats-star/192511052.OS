
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int req[50], n, head, size;
    int i, j, t, pos, cur, total = 0;

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

    printf("Enter disk size (number of cylinders): ");
    scanf("%d", &size);

    if (size <= 0 || head < 0 || head >= size) {
        printf("Invalid disk size or head position.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (req[i] < 0 || req[i] >= size) {
            printf("Invalid request position.\n");
            return 1;
        }
    }

    /* Sort requests */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                t = req[j];
                req[j] = req[j + 1];
                req[j + 1] = t;
            }
        }
    }

    /* Find first request >= head */
    for (pos = 0; pos < n && req[pos] < head; pos++);

    cur = head;

    printf("\nOrder of service: %d", head);

    /* Move towards higher cylinders */
    for (i = pos; i < n; i++) {
        total += abs(req[i] - cur);
        cur = req[i];
        printf(" -> %d", cur);
    }

    /* Move to last cylinder */
    total += (size - 1) - cur;
    printf(" -> %d", size - 1);

    /* Circular jump to cylinder 0 */
    total += size - 1;
    cur = 0;
    printf(" -> 0");

    /* Continue servicing remaining requests */
    for (i = 0; i < pos; i++) {
        total += abs(req[i] - cur);
        cur = req[i];
        printf(" -> %d", cur);
    }

    printf("\n\nTotal head movement = %d cylinders\n", total);
    printf("Average seek time = %.2f cylinders\n",
           (float)total / n);

    return 0;
}

