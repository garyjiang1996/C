#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void isleep(clock_t wait);

void main()
{
    long    i = 60000000L;
    clock_t start, finish;
    double  duration;
    // Delay for a specified time.
    printf("Delay for three seconds\n");
    isleep((clock_t)3 * CLOCKS_PER_SEC);
    printf("Done!\n");
    // Measure the duration of an event.
    printf("Time to do %ld empty loops is ", i);
    start = clock();
    printf("%ld\n", start);
    while (i--)
        ;
    finish = clock();
    printf("%ld\n", finish);
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%10.2f seconds\n", duration);
}
// Pauses for a specified number of milliseconds.
void isleep(clock_t wait)
{
    clock_t goal;
    goal = wait + clock();
    while (goal > clock())
        ;
}
