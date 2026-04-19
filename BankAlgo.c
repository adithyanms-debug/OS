#include <stdio.h>

int main() {
    int i, j, k;
    int nop, nor, need[50][50] = {0}, max[50][50] = {0}, alloc[50][50] = {0};
    int resources[50] = {0}, avlbl[50];
    int finished[50] = {0};

    printf("Enter the number of process : ");
    scanf("%d", &nop);

    printf("Enter the number of resources : ");
    scanf("%d", &nor);

    printf("Enter the allocation matrix\n");
    for(i = 1; i <= nop; i++) {
        for(j = 1; j <= nor; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    
    printf("Enter the maximum allocation matrix\n");
    for(i = 1; i <= nop; i++) {
        for(j = 1; j <= nor; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Enter the resources instance\n");
    for(i = 1; i <= nor; i++) {
        printf("R%d :- ", i);
        scanf("%d", &resources[i]);
    }

    for(i = 1; i <= nor; i++) {
        int rsum = 0;
        for(j = 1; j <= nop; j++) {
            rsum += alloc[j][i];
        }
        avlbl[i] = resources[i] - rsum;
    }

    int count = 0;
    printf("Safe sequence : ");
    while(1) {
        int progress = 0;
        for(int i = 1; i <= nop; i++) {
            if(finished[i] == 0) {
                for(j = 1; j <= nor; j++) {
                    if(avlbl[j] < need[i][j]) {
                        break;
                    }
                }
                if(j > nor) {
                    for(k = 1; k <= nor; k++) {
                        avlbl[k] = avlbl[k] + alloc[i][k];
                    }
                    finished[i] = 1;
                    count++;
                    progress = 1;
                    printf("P%d ", i);
                }
            }
        }
        if(!progress || count >= nop) {
            break;
        }
    }

    if(count == nop) {
        printf("No deadlock");
    } else {
        printf("Deadlock");
    }

    return 0;
}