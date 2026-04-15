#include <stdio.h>
int main() {

    int n, at[100], bt[100], tat[100], rem_bt[100], wt[100];
    int tq, time = 0, done;

    printf("Enter the number of process : ");
    scanf("%d", &n);

    printf("Enter the burst time\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter the arrival time\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter the time quantum : ");
    scanf("%d", &tq);

    while (1){
        done = 1;
        for(int i = 0; i < n; i++) {
            if(rem_bt[i] > 0 && at[i] <= time) {
                done = 0;
                if(rem_bt[i] > tq) {
                    time = time + tq;
                    rem_bt[i] = rem_bt[i] - tq;
                } else {
                    time = time + rem_bt[i];
                    wt[i] = time - bt[i] - at[i];
                    rem_bt[i] = 0;
                }
            } 
        }

        if(done == 1) {
            break;
        }
    }
    
    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}