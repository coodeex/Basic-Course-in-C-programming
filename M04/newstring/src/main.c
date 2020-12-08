#include <stdio.h>
#include "source.h"

int main()
{
    /* Implement your own tests here. Free feel to modify. */

    char str[] = "yksi,kaksi,kymmenen?nelja,viisi";

    // Testing 08_altstring.a
    qstr_print(str);
    
    // Testing 08_altstring.b
    printf("\nlength: %d\n", qstr_length(str));

    // Testing 08_altstring.c
    char buf[80] = "Viesti:?trtrttr";
    int ret = qstr_cat(buf, str);
    printf("After cat: '");
    qstr_print(buf);
    printf("' (ret: %d)\n", ret);

    // Testing 08_altstring.d
    const char *retptr = qstr_strstr(str, "kaksi?");
    if (!retptr)
        printf("qstr_strstr returned NULL: FALSE\n");
    else {
        printf("After qstr_strstr: ");
        qstr_print(retptr);
        printf("\n");
    }
    retptr = qstr_strstr(str, "nelja");
    if (!retptr)
        printf("qstr_strstr returned NULL: CORRECT\n");
    else
        printf("qstr_strstr returned: %s\n: FALSE\n", retptr);

    return 0;
}
