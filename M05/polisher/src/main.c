#include <stdio.h>
#include <stdlib.h>

#include "source.h"

/* Read given file <filename> to dynamically allocated memory.
 * Return pointer to the allocated memory with file content, or
 * NULL on errors.
 */
char *read_file(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return NULL;
    
    char *buf = NULL;
    unsigned int count = 0;
    const unsigned int ReadBlock = 100;
    unsigned int n;
    do {
        buf = realloc(buf, count + ReadBlock + 1);
        n = fread(buf + count, 1, ReadBlock, f);
        count += n;
    } while (n == ReadBlock);
    
    buf[count] = 0;
    
    return buf;
}


int main(void)
{
    char *code = read_file("testfile.c");
    if (!code) {
        printf("No code read");
        return -1;
    }
    printf("-- Original:\n");
    fputs(code, stdout);

    code = delete_comments(code);
    printf("-- Comments removed:\n");
    fputs(code, stdout);
   
    free(code);
}
