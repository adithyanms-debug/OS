#include <stdio.h>

int main() {

    int processSize[100], blockSize[100];
    int n, m;
    int allocation[100];

    printf("Enter the number of process : ");
    scanf("%d", &n);

    printf("Enter the number of blocks : ");
    scanf("%d", &m);

    printf("Enter the size of process\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    printf("Enter the block size\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    for(int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nP.No\tP.Size\tB.No\tB.Size\tFragments\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d\t%d\t%d\t%d\t%d\n", 
            i+1, 
            processSize[i],
            allocation[i]+1,
            processSize[i] + blockSize[allocation[i]],
            blockSize[allocation[i]]);
        } else {
            printf("%d\t%d\tNot Allocated\n", i+1, processSize[i]);
        }
        
    }
    return 0;
}