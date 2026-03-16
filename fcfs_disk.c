#include <stdio.h>

int main() {
    int i, seekTime = 0, totalRequests, requests[100], start;

    printf("Enter the head position : ");
    scanf("%d", &start);

    printf("Enter the total requests : ");
    scanf("%d", &totalRequests);

    printf("Enter the request sequence\n");
    for(int i = 0; i < totalRequests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Head movements : %d -> ", start);
    for(int i = 0; i < totalRequests; i++) {
        if(start < requests[i]) {
            seekTime += requests[i] - start;
        } else {
            seekTime += start - requests[i];
        }
        printf("%d -> ", requests[i]);
        start = requests[i];
    }

    printf("\nTotal seek time = %d", seekTime);

    return 0;

}