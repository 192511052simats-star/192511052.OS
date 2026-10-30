#include <stdio.h>

int main() {
    int n, quantum, time = 0, done = 0;
    int at[20], bt[20], rt[20], ct[20];
    int i;
    float twt = 0, ttat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("P%d arrival and burst time: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    while (done < n) {
        int progress = 0;

        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                progress = 1;

                if (rt[i] > quantum) {
                    time += quantum;
                    rt[i] -= quantum;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    done++;
                }
            }
        }

        
    }

  

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        int tat = ct[i] - at[i];
        int wt = tat - bt[i];

        twt += wt;
        ttat += tat;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat, wt);
    }

    printf("\nAverage TAT = %.2f\n", ttat / n);
    printf("Average WT = %.2f\n", twt / n);

    return 0;
}
