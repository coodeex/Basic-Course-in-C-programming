#include <stdio.h>
#include <string.h>
#include "source.h"

int main(void)
{
    char dest[200];

    /* The following helps detecting string errors, e.g. missing final nil */
    memset(dest, '#', 199);
    dest[199] = 0;
    
    printf("%s",
    	my_toupper(dest, "Otatko makkaraa? Se maksaa kaksi euroa. Ole hyvä.\n"));

    printf("%s",
    	my_toupper(dest, "Madam, where are you going? The health care center is over there.\n"));
    
    return 0;
}