#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char arr[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
// print tic tac toe board
void showBoard()
{
    system("cls");
    printf("\n-- TIC TAC TOE --\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c \n", arr[1], arr[2], arr[3]);
    printf("       |       |       \n");
    printf("-------|-------|-------\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c \n", arr[4], arr[5], arr[6]);
    printf("       |       |       \n");
    printf("-------|-------|-------\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c \n", arr[7], arr[8], arr[9]);
    printf("       |       |       \n");
}
// condition for winning and losing
int checkForWin()
{
    // Win cases
    // row cases
    if (arr[1] == arr[2] && arr[2] == arr[3])
        return 1;
    else if (arr[4] == arr[5] && arr[5] == arr[6])
        return 1;
    else if (arr[7] == arr[8] && arr[8] == arr[9])
        return 1;
    // column cases
    else if (arr[1] == arr[4] && arr[4] == arr[7])
        return 1;
    else if (arr[2] == arr[5] && arr[5] == arr[8])
        return 1;
    else if (arr[3] == arr[6] && arr[6] == arr[9])
        return 1;
    // diagonal cases
    else if (arr[1] == arr[5] && arr[5] == arr[9])
        return 1;
    else if (arr[3] == arr[5] && arr[5] == arr[7])
        return 1;

    // for game draw
    else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' && arr[4] != '4' && arr[5] != '5' && arr[6] != '6' && arr[7] != '7' && arr[8] != '8' && arr[9] != '9')
        return 0;

    else
        return -1;
}

int main()
{
    int player = 1;
    int choice, i;
    char mark; // x or o
    do
    {
        showBoard();
        player = (player % 2) ? 1 : 2;
        printf("Player %d turn: ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && arr[1] == '1')
        {
            arr[1] = mark;
        }
        else if (choice == 2 && arr[2] == '2')
        {
            arr[2] = mark;
        }
        else if (choice == 3 && arr[3] == '3')
        {
            arr[3] = mark;
        }
        else if (choice == 4 && arr[4] == '4')
        {
            arr[4] = mark;
        }
        else if (choice == 5 && arr[5] == '5')
        {
            arr[5] = mark;
        }
        else if (choice == 6 && arr[6] == '6')
        {
            arr[6] = mark;
        }
        else if (choice == 7 && arr[7] == '7')
        {
            arr[7] = mark;
        }
        else if (choice == 8 && arr[8] == '8')
        {
            arr[8] = mark;
        }
        else if (choice == 9 && arr[9] == '9')
        {
            arr[9] = mark;
        }
        else
        {
            printf("Invalid input!\n");
            player--;
            getch();
        }
        i = checkForWin(); //-1,0,1
        player++;
    } while (i == -1);

    showBoard();
    player--;
    if (i == 1)
    {
        printf("Player %d won!\n", player);
    }
    else
    {
        printf("Game Draw!\n");
    }
    getch();
    return 0;
}