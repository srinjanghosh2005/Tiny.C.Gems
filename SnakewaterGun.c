#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1--> snake, 2--> water, 3--> gun
int main()
{
    srand(time(0));
    // generate random number between 1 to 3
    int player, computer = (rand() % 3) + 1;

    printf("----Choose 1 for Snake, 2 for Water, 3 for Gun----\n");
    scanf("%d", &player);

    printf("%d\n", computer);

    if (player == 1)
    {
        if (computer == 1)
        {
            printf("Draw\n");
        }
        else if (computer == 2)
        {
            printf("Flawless Victory!!\n");
        }
        else
        {
            printf("Better Luck Next Time :( \n");
        }
    }

    if (player == 2)
    {
        if (computer == 1)
        {
            printf("Better Luck Next Time :( \n");
        }
        else if (computer == 2)
        {
            printf("Draw\n");
        }
        else
        {
            printf("Flawless Victory!!\n");
        }
    }

    if (player == 3)
    {
        if (computer == 1)
        {
            printf("Flawless Victory!!\n");
        }
        else if (computer == 2)
        {
            printf("Better Luck Next Time :( \n");
        }
        else
        {
            printf("Draw\n");
        }
    }
    return 0;
}