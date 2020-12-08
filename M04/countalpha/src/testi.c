#include "source.h"
#include "ctype.h"
#include "stdio.h"
#include <string.h>

char arr[] = "Terve ja hei ";

void main() {
    strncat(arr,arr, 5);
    printf("%ld", sizeof(arr));
    printf("%s", arr);
}