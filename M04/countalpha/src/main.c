#include <stdio.h>
#include <string.h>
#include "source.h"

int main()
{
    /* Count alpha */
    char *str = "How many alpha in this string?";
    printf("count_isalpha: %d\n", count_isalpha(str));
    
    return 0;
}