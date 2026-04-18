#include <stdio.h>
#include <stdlib.h>

int main() {

    int totalRequest, tracks[100], direction, start, end, headpos, seektime = 0;

    printf("Enter the total requests : ");
    scanf("%d", &totalRequest);

    printf("Enter the request sequence\n");
    for(int i = 1; i <= totalRequest; i++) {
        scanf("%d", &tracks[i]);
    }

    printf("Enter the head position : ");
    scanf("%d", &start);

    printf("Enter the right end of track : ");
    scanf("%d", &end);

    printf("Enter the direction(0 -> left and 1 -> right) : ");
    scanf("%d", &direction);

    tracks[0] = 0;
    tracks[totalRequest + 1] = start;
    tracks[totalRequest  + 2] = end;
    int size = totalRequest + 3;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - (i + 1); j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
            
        }
    }

    //find the head point after sorting
    for(int i = 0; i < size; i++) {
        if(tracks[i] == start) {
            headpos = i;
            break;
        }
    }

    printf("Elavator movement : ");
    if(direction == 1) {
        for(int i = headpos; i < size; i++) {
            printf("%d -> ", tracks[i]);
            seektime += abs(start - tracks[i]);
            start = tracks[i];
        }

        for(int i = headpos - 1; i >= 0; i--) {
            printf("%d -> ", tracks[i]);
            seektime += abs(start - tracks[i]);
            start = tracks[i];
        }
    } else if(direction == 0) {
        for(int i = headpos; i >= 0; i--) {
            printf("%d -> ", tracks[i]);
            seektime += abs(start - tracks[i]);
            start = tracks[i];
        }

        for(int i = headpos + 1; i < size; i++) {
            printf("%d -> ", tracks[i]);
            seektime += abs(start - tracks[i]);
            start = tracks[i];
        }
    } else {
        printf("Wrong input\n");
    }

    printf("Total seek time : %d\n", seektime);

    return 0;
}