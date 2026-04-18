#include <stdio.h>

int main()
{
    int i, j, resources[50] = {0}, need[50][50] = {0}, alloc[50][50] = {0}, max[50][50] = {0}, nop, nor, avlbl[50];
    int k;
    printf("Enter the total process : ");
    scanf("%d", &nop);

    printf("Enter the total resources : ");
    scanf("%d", &nor);

    printf("Enter the resource allocation matrix\n");
    for (i = 1; i <= nop; i++)
    {
        for (j = 1; j <= nor; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the max resource matrix\n");
    for (i = 1; i <= nop; i++)
    {
        for (j = 1; j <= nor; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Enter the total instance of each resources");
    for (i = 1; i <= nor; i++)
    {
        printf("R%d :-", i);
        scanf("%d", &resources[i]);
    }

    for (i = 1; i <= nor; i++)
    {
        int rsum = 0;
        for (j = 1; j <= nop; j++)
        {
            rsum += alloc[j][i];
        }
        alloc[j][i] = rsum;
        avlbl[i] = resources[i] - alloc[j][i];
    }

    int count = 0;
    while (1)
    {
        for (i = 1; i <= nop; i++)
        {
            if (need[i][nor + 1] == 0)
            {
                for (j = 1; j <= nor; j++)
                {
                    if (avlbl[j] < need[i][j])
                    {
                        break;
                    }
                }
                if (j > nor)
                {
                    for (k = 1; k <= nor; k++)
                    {
                        avlbl[k] = avlbl[k] + alloc[i][k];
                    }
                    need[i][nor + 1] = i;
                    count++;
                    printf("P%d -> ", i);
                }
            } else {
                count++;
            }
        }
        if(count >= nop) {
            break;
        }
    }

    return 0;
}