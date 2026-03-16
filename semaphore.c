#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;
int full = 0;

void produce()
{
    if (full == SIZE)
    {
        printf("Buffer is full!! Cannot produce\n");
        return;
    }
    int item;
    printf("Enter the item : ");
    scanf("%d", &item);
    buffer[in] = item;
    in = (in + 1) % SIZE;
    full++;
}

void consume()
{
    if (full == 0)
    {
        printf("The buffer is empty!! Cannot consume\n");
        return;
    }
    int item = buffer[out];
    printf("Consumed : %d\n", item);
    out = (out + 1) % SIZE;
    full--;
}

int main()
{

    int choice;
    while (1)
    {
        printf("1.Produce\n2.Consumer\n3.Exit\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            produce();
            break;
        case 2:
            consume();
            break;
        case 3:
            exit(0);
        default:
            printf("Entered the wrong input");
        }
    }

    return 0;
}