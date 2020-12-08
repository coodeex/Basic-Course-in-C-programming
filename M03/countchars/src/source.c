#include <stdio.h>

void printcounts(int min, int max, const unsigned int *counts) {
    for (int i = min; i <= max; i++) {
        printf("%c: %u  ---  ", i, counts[i]);
        if ((i - min + 1) % 6 == 0)
            printf("\n");
    } 
}

void printarray(const char *array) {
    printf("{ ");
    while (*array) {
        printf("'%c',", *array);
        array++;
    }
    printf("0 }");
}

unsigned int arraylen(const char *array)
{
    int i = 0;
    char c = 1;
    for(i; c != 0; i++){
        c = array[i];
    }
    return i - 1;
}

void countchars(const char *array, unsigned int *counts)
{
    char c = 1;
    for(int i = 0; c != 0; counts[c = array[i]]++ , i++);
}



int main()
{
     unsigned int counts[256] = { 0 };

     char sample[] = { 'a','b','r','a','c','a','d','a','b','r','a',0 };

     printf("%s, length: %u\n", sample, arraylen(sample));
     countchars(sample, counts);
     printcounts('a', 'z', counts);

    return 0;
}

