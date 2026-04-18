#include <stdio.h>

int main() {

    int n, m;
    int processSize[100], blockSize[100], allocation[100], orgBlockSize[100];
    int worst;

    printf("Enter the number of process : ");
    scanf("%d", &n);

    printf("Enter the number of blocks : ");
    scanf("%d", &m);

    printf("Enter the process sizes : ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    printf("Enter the block sizes : ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
        orgBlockSize[i] = blockSize[i];
    }

    for(int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        worst = -1;
        for(int j = 0; j < m; j++) {
            if(processSize[i] <= blockSize[j]) {
                if(worst == -1 || blockSize[j] > blockSize[worst]) {
                    worst = j;
                }
            }
        }

        if(worst != -1) {
            allocation[i] = worst;
            blockSize[worst] -= processSize[i];
        }
    }

    printf("P.NO\tP.SIZE\tB.NO\tB.SIZE\tFRAGEMENTS\n");
    for(int i = 0; i < n; i++) {
        if(allocation[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            i + 1,
            processSize[i],
            allocation[i] + 1,
            orgBlockSize[allocation[i]],
            blockSize[allocation[i]]
            );
        } else {
            printf("%d\t\t%d\tNot allocated", i + 1, processSize[i]);
        }
    }

    return 0;
}