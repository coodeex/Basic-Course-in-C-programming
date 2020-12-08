### Programming task 4.4: NO NEED TO SHOUT!!! (20 pts)

Implement a function with the following interface: `char *my_toupper(char
*dest, const char *src)`. Function argument *src* points to the string
that you should modify as described below. The modified string will be
written at address *dest*. In addition the function should return
pointer to the modified string (i.e., to the same address *dest*
originally points to).

The string should be modified in the following ways:

  * all letter characters should be changed to upper case. You can use
    function
    **[toupper](http://en.cppreference.com/w/c/string/byte/toupper)**,
    that converts one character to upper case for this. *toupper* is
    defined in header *ctype.h*, so you should add `#include
    <ctype.h>` at the beginning of your program if you decide to do
    this.

  * If the original string has a question mark ('?'), it should be
    changed to exclamation mark ('!').

  * If the original string has period ('.'), it should be replaced
    with three exclamation marks.

You will not modify the original string, but write the result in
location pointed by the *dest* variable.

For example the following main function:

#include <stdio.h>  // for printf
#include <string.h>  // for memset
#include <ctype.h>  // for toupper

int main(void)
{
    char dest[200];

    /* The following helps detecting string errors, e.g. missing final nil */
    memset(dest, '#', 199);
    dest[199] = 0;

    printf("%s",
    my_toupper(dest,
        "Would you like to have a sausage? It will be two euros. Here you are.\n"));

        printf("%s",
    my_toupper(dest,
        "Madam, where are you going? The health care center is over there.\n"));

    return 0;
}

Would output:

WOULD YOU LIKE TO HAVE A SAUSAGE! IT WILL BE TWO EUROS!!! HERE YOU ARE!!!
MADAM, WHERE ARE YOU GOING! THE HEALTH CARE CENTER IS OVER THERE!!!

Note that the *toupper* function does not necessary convert Ä and Ö
letters correctly. You don't need to worry about this.
