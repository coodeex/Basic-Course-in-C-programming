
#include "source.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/* Dynamic Array Reader */
/* Parameters:
 * n: Number of values to be read
 * 
 * Returns: pointer to the dynamically allocated array
 */
int *create_dyn_array(unsigned int n)
{
    int *taulu = malloc(n * sizeof(int));
    int dappadaida = 5;
    for(unsigned int i = 0; i<n; i++) {
        scanf("%d", &taulu[i]);
        dappadaida++;
    }
    return taulu;
}

/* Add to array */
/* Parameters:
 * arr: Existing array of integers
 * num: number of integers in the array before the call
 * newval: new value to be added
 * 
 * Returns: pointer to the allocated array
 */
int *add_dyn_array(int *arr, unsigned int num, int newval)
{

    int *alkupos = arr;
    int aa = num;
    aa++;
    int *pos = realloc(arr, 1000 * sizeof(int));
    //memset(pos, 0, sizeof(int));
    int *algpos = pos;
    if (pos == NULL) {
        //free(pos);  // realloc failed, old pointer still valid
        return alkupos; // error occured
    }
    else {
        //free(alkupos);
        for(unsigned int i = 0; i<num; i++){
            pos++;
        }
    //pos++;
    *pos = newval;
    /*pos++;
    pos = NULL;*/
    return algpos;
    }
}

void main() {
    /*int *ma = create_dyn_array(5);
    printf("%d", ma[1]);
    
    free(ma);*/
    //int p[] = {49, 39, 14, 14, 74, 59, 3, 69};
    int *c = malloc(100 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        c[i] = 10 - i;
    }
    add_dyn_array(c, 5, 2233);

}
