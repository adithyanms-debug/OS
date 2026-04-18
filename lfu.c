#include <stdio.h>
int main() {

    int nop, nof, rs[100], fault = 0, hit = 0, frames[100];
    int feq[100];
    int i, j;

    printf("Enter the number of process : ");
    scanf("%d", &nop);

    printf("Enter the refernece string\n");
    for(i = 1; i <= nop; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Enter the frame : ");
    scanf("%d", &nof);

    for(i = 1; i <= nof; i++) {
        frames[i] = -1;
        feq[i] = 0; 
        printf("Frames %d", i);
    }

    printf("\n");

    for(i = 1; i <= nop; i++) {
        for(j = 1; j <= nof; j++) {
            if(frames[j] == rs[i]) {
                hit++;
                feq[j]++;
                break;
            } else if(frames[j] == -1) {
                fault++;
                frames[j] = rs[i];
                feq[j] = 1;
                break;
            }
        }

        if(j > nof) {
            fault++;
            int lfu = 1;
            for(j = 2; j <= nof; j++) {
                if(feq[j] < feq[lfu]) {
                    lfu = j;
                }
            }
            frames[lfu] = rs[i];
            feq[lfu] = 1;
        }
        for(j = 1; j <= nof; j++) {
                if(frames[j] == -1) {
                    printf("%c\t", 'E');
                } else {
                    printf("%d\t", frames[j]);
                }
            }
        printf("\n");
    }

    printf("\nPage faults = %d\nHit ratio = %f\n", fault, (float)hit/nop);

    return 0;
}