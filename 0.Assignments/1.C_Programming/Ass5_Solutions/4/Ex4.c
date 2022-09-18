/**
 * @file Ex4.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex4
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @struct TIME
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
struct TIME
{
  int seconds;  // 0 to 59
  int minutes;  // 0 to 59
  int hours;    // 0 to 23
};

void differenceBetweenTimePeriod(struct TIME t1, struct TIME t2, struct TIME *diff);

/**
 * @brief Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main()
{
    struct TIME startTime, stopTime, diff;

    printf("Enter start time: \n");
    printf("Enter hours, minutes and seconds respectively: ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    printf("Enter stop time: \n");
    printf("Enter hours, minutes and seconds respectively: ");
    scanf("%d %d %d", &stopTime.hours, &stopTime.minutes, &stopTime.seconds);

    // Calculate the difference between the start and stop time period.
    differenceBetweenTimePeriod(startTime, stopTime, &diff);

    printf("\nTIME DIFFERENCE: %d:%d:%d - ", startTime.hours, startTime.minutes, startTime.seconds);
    printf("%d:%d:%d ", stopTime.hours, stopTime.minutes, stopTime.seconds);
    printf("= %d:%d:%d\n", diff.hours, diff.minutes, diff.seconds);

    return 0;
}

/**
 * @brief differenceBetweenTimePeriod
 * 
 * @param start 
 * @param stop 
 * @param diff 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void differenceBetweenTimePeriod(struct TIME start, struct TIME stop, struct TIME *diff)
{
    if(stop.seconds > start.seconds){
        --start.minutes;
        start.seconds += 60;
    }

    diff->seconds = start.seconds - stop.seconds;
    if(stop.minutes > start.minutes){
        --start.hours;
        start.minutes += 60;
    }

    diff->minutes = start.minutes - stop.minutes;
    diff->hours = start.hours - stop.hours;
}