#include <stdio.h>
#include "source.h"

void printcounts(int min, int max, const unsigned int *counts) {
    for (int i = min; i <= max; i++) {
        printf("%c: %u  ---  ", i, counts[i]);
        if ((i - min + 1) % 6 == 0)
            printf("\n");
    }
}

void printarray(const char *array) {
    printf("{ ");
    while (*array) {
        printf("'%c',", *array);
        array++;
    }
    printf("0 }");
}

int main(void)
{
    unsigned int counts[256] = { 0 };

    char sample[] = { 'a','b','r','a','c','a','d','a','b','r','a',0 };

    printarray(sample);
    printf(", length: %u\n", arraylen(sample));
    countchars(sample, counts);
    printcounts('a', 'z', counts);

    return 0;
}
