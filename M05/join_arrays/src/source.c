
#include "source.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int* join_arrays(unsigned int n1, const int *a1,
		 unsigned int n2, const int *a2,
		 unsigned int n3, const int *a3)
{
	int c = n1 + n2 + n3 + 10;
    int *super = malloc(c * sizeof(int));
	int *fail = NULL;
	int *ogsuper = super;
	if(super == NULL){
		return fail;
	}
	for(unsigned int a = 0; a < n1; a++){
		*super++ = *a1++;
	}
	for(unsigned int b = 0; b < n2; b++){
		*super++ = *a2++;
	}
	for(unsigned int c = 0; c < n3; c++){
		*super++ = *a3++;
	}
	return ogsuper;
}
