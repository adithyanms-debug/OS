#include <stdio.h>

int main() {
    
    int nop, nor, i, j, k;
    int alloc[100][100] = {0}, max[100][100] = {0}, need[100][100] = {0};
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
    
    printf("Enter the total resource instance : ");
    for(i = 1; i <= nor; i++) {
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
        for(i = 1; i <= nop; i++) {
            if(finished[i] == 0) {
                for(j = 1; j <= nor; j++) {
                    if(avlbl[j] < need[i][j]) {
                        break;
                    }
                }
                if(j > nor) {
                    for(k = 1; k <= nor; k++) {
                        avlbl[k] += alloc[i][k];
                    }
                    count++;
                    finished[i] = 1;
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
        printf("No deadlock\n");
    } else {
        printf("Deadlock\n");
    }
    
    int pid;
    int request[50];
    printf("Enter the process number : ");
    scanf("%d", &pid);
    
    printf("Enter the request : ");
    for(i = 1; i <= nor; i++) {
        scanf("%d", &request[i]);
    }
    
    for(i = 1; i <= nor; i++) {
        if(request[i] > need[pid][i]) {
            printf("Request denied\n");
            return 0;
        }
    }
    
    for(i = 1; i <= nor; i++) {
        if(request[i] > avlbl[i]) {
            printf("Need to wait\n");
            return 0;
        }
    }
    
    for(i = 1; i <= nor; i++) {
        avlbl[i] -= request[i];
        alloc[pid][i] += request[i];
        need[pid][i] -= request[i];
    }
    
    printf("Request granted\n");
    
    return 0;
}