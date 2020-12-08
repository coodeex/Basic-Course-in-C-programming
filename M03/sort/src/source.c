
#include "source.h"
#include <stdio.h>

/* Selection sort */
/* Parameters:
 * start: start of an array
 * size: length of an array
 */
void sort(int *start, int size)
{
    int i, a, apu;
    for(i = 0; i < size - 1; i++) {
        int c = i;
        for(a = i + 1; a < size; a++) {
            if(start[a] < start[c]) {
                c = a;
            }     
        }
        apu = start[i];
        start[i] = start[c];
        start[c] = apu;
    }
}

void main() {
    int arr[5] = {2,4,7,1,3};
    sort(arr, 5);
    for (int j = 0; j < 5; j++ ) {
      printf("Element[%d] = %d\n", j, arr[j] );
   }
}
