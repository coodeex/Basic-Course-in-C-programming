#include <stdio.h>
#include <math.h>
#include "source.h"

void draw_triangle(unsigned int size)
{
    for(int a = 0; a < size; a++) {

        for(int b = 0; b < size - a - 1; b++) {
            printf("%c", '.');
        }
        for(int c = 0; c < a + 1; c++) {
            printf("%c", '#');
        }
        printf("\n");
    }
}

void main() {
    draw_triangle(100);
}
