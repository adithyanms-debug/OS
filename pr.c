#include <stdio.h>

int main() {

    int n, p[100], tat[100], bt[100], wt[100], pr[100];

    printf("Enter the number of process : ");
    scanf("%d", &n);

    printf("Enter the burst time and priority\n");
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &bt[i], &pr[i]);
        p[i] = i + 1;
    }

    // sorting based on priority
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(pr[i] > pr[j]) {

                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\nProcess\tBurst\tPriority\tWait\tTat\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}