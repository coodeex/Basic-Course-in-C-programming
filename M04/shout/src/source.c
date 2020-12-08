#include "source.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char *my_toupper(char *dest, const char *src)
{
 

    int i = 0;
    while(*src != '\0'){
        if(*src == '?'){
            *dest = '!';
            //continue;
        }
        else if(*src == '.'){
            for(int a = 0; a < 3; a++){
            *dest = '!';
            i++;
            dest++;
            }
            src = src + 1;
            continue;
        }
        else{
            *dest = toupper(*src);
        }
    i++;
    src++;
    dest++;
    }
    *dest = '\0';
    /*i++;
    *(dest+1)= '\0';
    
    //dest - i;*/
   // printf("%s",dest);

    return dest - i;

}




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
