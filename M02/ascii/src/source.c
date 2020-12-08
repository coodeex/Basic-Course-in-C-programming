#include "source.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char onks(int c) {
    char d;
   	if (isprint(c)!= 0)
             d = c;
    else d = '?';
    return d;
}

void ascii_chart(char min, char max) {
    int las = 1;
    for(int a = min; a <= max; a++, las++){
        if (las % 4 == 0) printf("%3d 0x%02x %c\n", a, a, onks(a));
        else printf("%3d 0x%02x %c\t", a, a, onks(a));
    }
}


int main(void) {
    ascii_chart(1,110);
   // printf("%d", isprint('a'));
}
