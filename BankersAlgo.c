#include <stdio.h>
void main() {
    int resource[50] = {0}, alloc[50][50] = {0}, max[50][50] = {0}, nop, nor, avlbl[50] = {0};
    int need[50][50] = {0};
    int i, j, k;
    printf("Enter the number of process : ");
    scanf("%d", &nop);

    printf("Enter the number of resources : ");
    scanf("%d", &nor);

    printf("Enter resources allocation matrix\n");
    for(i = 0; i < nop; i++) {
        for(j = 0; j < nor; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter maximum resources allocation\n");
    for(i = 0; i < nop; i++) {
        for(j = 0; j < nor; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Enter the total instance of each resources\n");
    for(i = 0; i < nor; i++) {
        printf("R%d :- ", i);
        scanf("%d", &resource[i]);
    }

    for(i = 0; i < nor; i++) {
        int rsum = 0;
        for(j = 0; j < nop; j++) {
           rsum += alloc[j][i];
        }
        avlbl[i] = resource[i] - rsum;
    }

    int count = 0;
    while(1) {
        for(i = 0; i < nop; i++) {
            if(need[i][nor + 1] == 0) {
                int canRun = 1;
                for(j = 0; j < nor; j++) {
                    if(avlbl[j] < need[i][j]) {
                        canRun = 0;
                        break;
                    } 
                }
                if(canRun) {
                    for(k = 0; k < nor; k++) {
                        avlbl[k] = avlbl[k] + alloc[i][k];
                    }
                    need[i][nor + 1] = 1;
                    count++;
                    if(count < nop)
                        printf("P%d -> ", i);  // print arrow only if not last
                    else
                        printf("P%d", i);      // no arrow for last process
                }
            }
        }
        if(count == nop) {
            break;
        }
    }
    
}