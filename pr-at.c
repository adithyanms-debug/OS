#include <stdio.h>

int main() {

    int n, p[100], tat[100], bt[100], wt[100], pr[100], at[100];

    printf("Enter the number of process : ");
    scanf("%d", &n);

    printf("Enter arrival time, burst time and priority\n");
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
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

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int current_time = 0;

    // waiting time calculation considering arrival time
    for(int i = 0; i < n; i++) {

        if(current_time < at[i]) {
            current_time = at[i];  // CPU idle
        }

        wt[i] = current_time - at[i];
        current_time += bt[i];
    }

    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", p[i], at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}