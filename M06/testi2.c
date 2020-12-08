
#include <stdio.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

struct pet;

char *t ="abbaacdc";

struct person {
    const char *name;
    int age;
    char nk[2];
    char *autot[10];
};
int main(void)
{
    /*struct person johu = {"Johannes", 5};
    johu.nk[0] = 'J';
    johu.nk[1] = 'T';
    johu.autot[0] = "Lada";
    johu.autot[1] = "Valgee mersu";
    johu.autot[2] = "RättiCitikka";
    printf("%s\n", johu.name);
    printf("%d\n", johu.age);
    printf("%c.%c\n", johu.nk[0], johu.nk[1]);
    printf("Autot:\n 1. %s\n 2. %s\n 3. %s\n\n",
    johu.autot[0], johu.autot[1], johu.autot[2]);
    printf("%ld", strlen(t));*/
    unsigned int a;
    if(strlen("")==0){
        a=1;
    }
    else a = 5;
    printf("%u", a);
}