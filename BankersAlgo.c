#include <stdio.h>

int main() {
    int i, j, k;
    int resources[50] = {0}, need[50][50] = {0};
    int alloc[50][50] = {0}, max[50][50] = {0};
    int nop, nor, avlbl[50];
    int finished[50] = {0};  // ✅ dedicated visited array

    printf("Enter the total processes: ");
    scanf("%d", &nop);

    printf("Enter the total resources: ");
    scanf("%d", &nor);

    printf("Enter the resource allocation matrix:\n");
    for (i = 1; i <= nop; i++)
        for (j = 1; j <= nor; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the max resource matrix:\n");
    for (i = 1; i <= nop; i++)
        for (j = 1; j <= nor; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }

    printf("Enter the total instances of each resource:\n");
    for (i = 1; i <= nor; i++) {
        printf("R%d: ", i);
        scanf("%d", &resources[i]);
    }

    // ✅ Fix Bug 1: use rsum directly
    for (i = 1; i <= nor; i++) {
        int rsum = 0;
        for (j = 1; j <= nop; j++)
            rsum += alloc[j][i];
        avlbl[i] = resources[i] - rsum;
    }

    int count = 0;
    printf("\nSafe sequence: ");

    // ✅ Fix Bug 2: progress flag prevents infinite loop
    while (1) {
        int progress = 0;
        for (i = 1; i <= nop; i++) {
            if (finished[i] == 0) {          // ✅ Fix Bug 3
                for (j = 1; j <= nor; j++)
                    if (avlbl[j] < need[i][j])
                        break;

                if (j > nor) {
                    for (k = 1; k <= nor; k++)
                        avlbl[k] += alloc[i][k];
                    finished[i] = 1;         // ✅ Fix Bug 4
                    count++;
                    progress = 1;
                    printf("P%d ", i);
                }
            }
        }
        if (!progress || count >= nop) break;
    }

    if (count == nop)
        printf("\nNo Deadlock, system is safe.");
    else
        printf("\nDeadlock detected.");

    return 0;
}   