#include <stdio.h>
int main() {

    int n, tat[100], bt[100], at[100], wt[100], p[100], temp;

    printf("Enter the number of process : ");
    scanf("%d", &n);

    printf("Enter the burst time\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    printf("Enter the arrival time\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", at[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1] - at[i]  +at[i - 1];
    }

    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}