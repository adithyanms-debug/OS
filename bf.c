#include <stdio.h>

int main() {

    int processSize[100], blockSize[100];
    int n, m, best;
    int allocated[100];

    printf("Enter the number of process : ");
    scanf("%d", &n);

    printf("Enter the number of block : ");
    scanf("%d", &m);

    printf("Enter process size\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    printf("Enter block size\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    for(int i = 0; i < n; i++) {
        allocated[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        best = -1;

        for(int j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(best == -1 || blockSize[j] < blockSize[best]) {
                    best = j;
                }
            }
        }

        if(best != -1) {
            allocated[i] = best;
            blockSize[best] -= processSize[i];
        }
    }
    
     printf("\nP.No\tP.Size\tB.No\tB.Size\tFragment\n");

    for(int i=0;i<n;i++) {

        if(allocated[i] != -1)
            printf("%d\t%d\t%d\t%d\t%d\n",
                i+1,
                processSize[i],
                allocated[i]+1,
                processSize[i] + blockSize[allocated[i]],
                blockSize[allocated[i]]);
        else
            printf("%d\t%d\tNot Allocated\n", i+1, processSize[i]);
    }

    return 0;
}