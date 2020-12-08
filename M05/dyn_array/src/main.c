#include <stdlib.h>
#include <stdio.h>
#include "source.h"

void printarray(const int *array, int size) {
    printf("{ ");
    for (int i = 0; i < size; ++i) {
        printf("%d, ", array[i]);
    }
    printf(" }\n");
}

int main()
{
    /* testing exercise. Feel free to modify */
    int *array = create_dyn_array(5);
    printarray(array, 5);
    
    array = add_dyn_array(array, 5, 10);
    printarray(array, 6);
    
    array = add_dyn_array(array, 6, 100);
    printarray(array, 7);
    
    array = add_dyn_array(array, 7, 1000);
    printarray(array, 8);
    
    return 0;
}
