#include <stdio.h>
#include "source.h"
#include <math.h>

double vectorlength(double x, double y, double z) {
    double length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    return length;
}

int main(void)
{
    /* Feel free to modify this code to test with different inputs */
    printf("Length of vector (1,2,3): %f\n", vectorlength(1,2,3));
    printf("Length of vector (1,1,1): %f\n", vectorlength(1,1,1));
    printf("Length of vector (1,0,0): %f\n", vectorlength(1,0,0));    
    printf("Length of vector (0.3, 0.3, 0.1): %f\n",
	   vectorlength(0.3, 0.3, 0.1));
}
