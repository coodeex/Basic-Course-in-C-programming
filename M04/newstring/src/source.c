#include "source.h"
#include "stdio.h"
#include <stddef.h>



/* Print string */
/* Parameters:
 * s: string to be printed */
/*void qstr_print(const char *s)
{
    while(*s != '?') {
        printf("%c", s);
        s++;
    }
}
*/
void qstr_print(const char *s)
{
    for(int i = 0; s[i] != '?'; i++) {
        printf("%c", s[i]);
    }
}


/* String length */
/* Parameters:
 * s: string to be evaluated
 * Returns: length of the string */
unsigned int qstr_length(const char *s)
{
    int i = 0;
    while (s[i] != '?'){
        i++;
    }
    return i;
}

/* String cat */
/* Parameters:
 * dst: buffer to which the new string is appended
 * src: string to be appended
 * Returns: Number of characters in the new string */
int qstr_cat(char *dst, const char *src)
{
    int i = 0;
    while(*dst != '?') {
        dst++;
        i++;
    }
    while(*src != '?'){
        *dst = *src;
        src++;
        dst++;
        i++;
    }
    *dst = '?';
    return i;
}

/* String strstr */
const char *qstr_strstr(const char *str1, const char *str2)
{
    while (*str1 != '?'){
        const char *a = str1;
        const char *b = str2;
        while (*str1 != '?' && *b != '?' && *str1 == *b) //*str1 && *b && *str1 == *b) {
            {
                str1++;
                b++;
            }
        if (*b == '?'){
                return a;
            }
                    
        str1 = a + 1;	
        
    }
    return NULL;
}

void main() {
    /*const char *str = "Auto ajoi?kilparataa";
    qstr_print(str);
    printf("\n%d\n", qstr_length(str));

    char dst[50] = "v?iisibazfoo";
    char *src = "v?iisibazfoo";
    printf("\n\n%d \n", qstr_cat(dst, src));
    qstr_print(dst);*/
    printf("num %d\n", qstr_length("erkkiS?"));

    const char s [] = "asdfghj?";
   
    printf ("Returned: %s\n", qstr_strstr(s, "dfg?"));
 



}