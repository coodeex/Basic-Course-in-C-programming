#include "source.h"
#include "ctype.h"
#include "stdio.h"

/* Count Alpha
 * Count number of alphabetic characters in the given string <str>,
 * and return the count
 */
int count_isalpha(const char *str)
{
    int c = 0;
    while(*str != '\0'){
        if(isalpha(*str)){
            c++;
        }
        str++;
    }
    return c;
}

int main(void) {
    char stringi[] = "heloust heloues";
    printf("%d", count_isalpha(stringi));
}