#include "hexread.h"
#include <stdlib.h>
#include <stdio.h>


/* Prints the given file as hexdump, at most 16 numbers per line.
 * <filename> parameter is the name of the file.
 * 
 * Returns the number of characters read
 */
int file_to_hex(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "Opening file failed\n");
        return -1;
    }
    int g = fgetc(f);
    int i=1;
    for(; g!=-1; i++){
        printf("%02x ", g & 0xff);
        if(i%16==0)printf("\n");
        g = fgetc(f);
    }
    return i-1;
}
