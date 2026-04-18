#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, req[100], head, size, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter request sequence:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("Enter disk size: ");
    scanf("%d",&size);

    // Add boundary points
    req[n] = 0;
    req[n+1] = size-1;
    int total = n + 2;

    // Sort
    for(int i=0;i<total-1;i++)
        for(int j=0;j<total-i-1;j++)
            if(req[j] > req[j+1]) {
                int t = req[j];
                req[j] = req[j+1];
                req[j+1] = t;
            }

    int pos;
    for(int i=0;i<total;i++) {
        if(req[i] >= head) {
            pos = i;
            break;
        }
    }

    printf("Head Movement:\n%d -> ", head);

    // Move right
    for(int i=pos;i<total;i++) {
        seek += abs(head - req[i]);
        head = req[i];
        printf("%d -> ", head);
    }

    // Jump to start (IMPORTANT FIX)
    seek += abs(head - 0);
    head = 0;
    printf("0 -> ");

    // Continue
    for(int i=0;i<pos;i++) {
        seek += abs(head - req[i]);
        head = req[i];
        printf("%d -> ", head);
    }

    printf("\nTotal seek time = %d\n", seek);

    return 0;
}