#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "source.h"

int main()
{
    int valarray[] = { 10, 100, 1000 };
    printf("array_sum with values { 10, 100, 1000 } returned: ");
    int sum = array_sum(valarray, 3);
    
    if (sum == 1110) {
        printf("%d -- OK!\n", sum);
    } else {
        printf("%d, but should have been 1110\n", sum);
    }

    int ints[10];
    printf("Read %d integers!\n", array_reader(ints, 10));
   
    return 0;
}
