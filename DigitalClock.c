#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int hour, minute, second;
    hour = minute = second = 0;

    while (1)
    {
        // clear output screen
        system("cls");

        // print time in HH:MM:SS format
        printf("%02d:%02d:%02d", hour, minute, second);

        // clear output buffer in gcc
        fflush(stdout);

        // increase second
        second++;

        // update hour
        if (second == 60)
        {
            second = 0;
            minute++;
        }
        if (minute == 60)
        {
            minute = 0;
            hour++;
        }
        if (hour == 24)
        {
            hour = 0;
            minute = 0;
            second = 0;
        }
        sleep(1); // wait till one second
    }
    
    return 0;
}
