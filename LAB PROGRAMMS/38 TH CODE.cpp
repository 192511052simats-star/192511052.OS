
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int req[50], n, head, i, j, t, pos, cur, total = 0;

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

    /* Sort the requests */
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

    /* Move towards lower cylinders */
    for (i = pos - 1; i >= 0; i--) {
        total += abs(req[i] - cur);
        cur = req[i];
        printf(" -> %d", cur);
    }

    /* Move to cylinder 0 */
    total += cur;
    cur = 0;
    printf(" -> 0");

    /* Move towards higher cylinders */
    for (i = pos; i < n; i++) {
        total += abs(req[i] - cur);
        cur = req[i];
        printf(" -> %d", cur);
    }

    printf("\n\nTotal head movement = %d cylinders\n", total);

    return 0;
}

