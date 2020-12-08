#include "source.h"

#include <stdio.h>
#include <math.h>

void simple_multiply(void)
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a * b;
    printf("%d * %d = %d\n",a, b, c);
}


void simple_math(void)
{
    float num1, num2;
    char ope = 0;
    scanf("%f %c %f", &num1, &ope, &num2);
    switch(ope) {
        case'+':
            printf("%.1f\n", num1 + num2);
            break;
        case'-':
            printf("%.1f\n", num1 - num2);
            break;
        case'*':
            printf("%.1f\n", num1 * num2);
            break;
        case'/':
            printf("%.1f\n", num1 / num2);
            break;
        default:
            printf("ERR\n");
        
    }
    
}

int main(void) {
    simple_math();
}




