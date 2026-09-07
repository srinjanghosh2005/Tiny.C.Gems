#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize random number generator
    srand(time(0));

    // gnerate random number between 1 ad 100
    int randomNumb = (rand() % 100) + 1;

    int noOfGuesses = 0;
    int guessedNumb;

    do
    {
        printf("--Guess the number--\n");
        scanf("%d", &guessedNumb);

        // condition for higher or lower number
        if (guessedNumb > randomNumb)
        {
            printf("Choose a smaller number!\n");
        }
        else
        {
            printf("Choose a bigger number!\n");
        }
        noOfGuesses++;
    } while (guessedNumb != randomNumb);

    // print total number of guesses
    printf("\nTotal number of guesses: %d\n", noOfGuesses);

    if (noOfGuesses <= 5)
    {
        printf("\n :) well played!!\n");
    }
    else
    {
        printf("\n :( Better luck next time lil bro!!\n");
    }

    return 0;
}