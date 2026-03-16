#include <stdio.h>

int main() {
    int nop, nof, i , j, frames[100], rs[100], fault = 0, start = 0, hit = 0;
    int recent[100];

    printf("Enter the number of process : ");
    scanf("%d", &nop);

    printf("Enter the reference string\n");
    for(int i = 1; i <= nop; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Enter the number of frames : ");
    scanf("%d", &nof);

    for(i = 1; i <= nof; i++) {
        frames[i] = -1;
        recent[i] = 0;
        printf("Frames %d", i);
    }

    for(i = 1; i <= nop; i++) {
        for(j = 1; j <= nof; j++) {
            if(frames[j] == rs[i]) {
                hit++;
                recent[j] = i;
                break;
            } else if(frames[j] == -1){
                fault++;
                frames[j] = rs[i];
                recent[j] = i;
                break;
            }
        }

        if(j > nof) {
            fault++;
            int lru = 1;
            for(j = 2; j <= nof; j++) {
                if(recent[j] < recent[lru]) {
                    lru = j;
                }
                frames[lru] = rs[i];
                recent[lru] = i;
            }

            for(j = 1; j <= nof; j++) {
                if(frames[i] == -1) {
                    printf("%c\t", 'E');
                } else {
                    printf("%d\t", frames[i]);
                }
            }
        }
        printf("\n");
    }

    printf("\nPage faults = %d\nHit ratio = %f\n", fault, (float)hit/nop);
    return 0;
}