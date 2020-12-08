#include <stdio.h>
#include <string.h>
#include "source.h"

// can be used for checking what the array looks like
void print_array(int *ar, int s)
{
    int i;
    for (i = 0; i < s-1; i++) printf("%d, ", ar[i]);
    printf("%d\n", ar[i]);
}

int main()
{
    /* Sort. Implement a function to print
     * the resulting array to see that it really works */ 
    int arr[] = {3, 4, 7, 2, 8};
    sort(arr, 5);
    print_array(arr, 5);
    
    return 0;
}
