#include <stdio.h>
#include <stdlib.h>

int main() {
    int totalRequest, tracks[100], start, end, seektime = 0, headpos;
    printf("Enter the number of total request : ");
    scanf("%d", &totalRequest);

    printf("Enter the request sequence \n ");
    for(int i = 1; i <= totalRequest; i++) {
        scanf("%d", &tracks[i]);
    }

    printf("Enter the initial index : ");
    scanf("%d", &start);

    printf("Enter the end : ");
    scanf("%d", &end);

    tracks[0] = 0;
    tracks[totalRequest + 1] = start;
    tracks[totalRequest + 2] = end;
    int size = totalRequest + 3;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - (i + 1); j++) {
            if(tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++) {
        if(tracks[i] == start) {
            headpos = i;
            break;
        }
    }

    for(int i = headpos; i < size; i++) {
        printf("%d -> ", tracks[i]);
        seektime += abs(start - tracks[i]);
        start = tracks[i];
    }

    seektime += abs(end - 0);
    start = 0;

    for (int i = 0; i < headpos; i++) {
        printf("%d -> ", tracks[i]);
        seektime += abs(start - tracks[i]);
        start = tracks[i];
    }

    printf("Total seek time : %d", seektime);
    
}
