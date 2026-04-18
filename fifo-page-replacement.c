#include <stdio.h>

int main() {

    int rs[100], frames[100], i, j, nop, nof, fault = 0, hit = 0;
    
    printf("Enter the number of pages : ");
    scanf("%d", &nop);

    printf("Enter the reference string \n");
    for (i = 1; i <= nop; i++) {
        scanf("%d", &rs[i]);
    }
    
    printf("Enter the number of frames : ");
    scanf("%d", &nof);
    for(i = 1; i <= nof; i++) {
        frames[i] = -1;
        printf("Frames%d\t", i); // FIX 1: was printf("Frames%d\t", j) - j was uninitialized, changed to i
    }
    printf("\n");

    for(i = 1; i <= nop; i++) {
        for(j = 1; j <= nof; j++) {
            if(frames[j] == rs[i]) { // FIX 2: hit check moved before empty check to correctly detect hits
                hit++;
                break;
            } else if(frames[j] == -1) { // FIX 3: empty frame check moved after hit check
                fault++;
                frames[j] = rs[i];
                break;
            }
        } // FIX 4: removed the if(j > nof) block from inside inner loop, now placed outside below
        if(j > nof) { // FIX 5: this block was inside inner for loop where j > nof was unreachable, moved outside
            fault++;
            frames[((fault - 1) % nof) + 1] = rs[i]; // FIX 6: was frames[fault % nof] = rs[i] which gave wrong index, corrected FIFO replacement
        }
        for(j = 1; j <= nof; j++) { // FIX 7: display loop was using i as loop variable corrupting outer loop, changed to j
            if(frames[j] == -1) {
                printf("%c\t", 'E');
            } else {
                printf("%d\t", frames[j]); // FIX 8: was printf("%d\t", frames[j]) with wrong i-based indexing inside i loop, now correct with j
            }
        }
        printf("\n");
    }

    printf("\nPage faults = %d\nHit ratio = %f\n", fault, (float)hit/nop);

    return 0;
}