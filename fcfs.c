#include <stdio.h>

int main() {

    int n, bt[100], wt[100], tat[100];

    printf("Enter the number of process : ");
    scanf("%d", &n);

    printf("Enter the burst time\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for(int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    

    return 0;
}