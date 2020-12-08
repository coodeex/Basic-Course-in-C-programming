#include <stdio.h>
#include "source.h"


/* Array Sum
 * Calculate the sum of integers in array starting at address <array>.
 * There will be <count> elements in array. Return the sum as return value.
 */
int array_sum(int *array, int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum = sum + array[i];
    }
    return sum;
}

/* Array Reader */
/* Parameters:
 * vals: array to be filled
 * n: maximum size of array
 * returns: number of values read */
unsigned int array_reader(int *vals, int n)
{
    int i = 0;
    int c = 1;
    for(i; c == 1 && i < n; i++) {
        c = scanf("%d", &vals[i]);
    }
    return i - 1;
}

void main() {
    /*int valarray[] = { 10, 100, 1000 };
    int ret = array_sum(valarray, 3);
    printf("%d", ret);*/
    int array[10];
    unsigned int n = array_reader(array, 10);
    printf("%d numbers read\n", n);
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}