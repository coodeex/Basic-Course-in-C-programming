#include "stringsplit.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Split string by another string, return split parts + NULL in array.
 *
 * Parameters: 
 *  str: the string to split
 *  split: the string to split str with
 *
 * Returns:
 *  A dynamically reserved array of dynamically reserved string parts.
 *
 * For example called with "Test string split" and " ",
 * returns ["Test", "string", "split", NULL].
 * Or called with "Another - test" and " - ",
 * returns ["Another", "test", NULL].
 */


char** split_string(const char *str, const char* split) {
    char **taulu;
    taulu = malloc(sizeof(*taulu));  // pitäis joskus realloccaa
    if (taulu == NULL){ /* check */
            return NULL;
        }
    //char *a = *str;
    char *p = strstr(str, split);
    int i = 0;
    for(; p != NULL ;i++){
        int e = p - str;
        taulu = realloc(taulu, (i+1)* sizeof(*taulu));
        if (taulu == NULL){
                return NULL;
        }
        taulu[i] = malloc((e+1) * sizeof(char));
        if (taulu[i] == NULL){
                return NULL;
        }
        strncpy(taulu[i], str, e);
        taulu[i][e] = '\0';
        str = str + e + strlen(split);
        p = strstr(str, split);
        if(p == NULL){
                taulu = realloc(taulu, (i+3)* sizeof(*taulu));
                if (taulu == NULL){ /* check */
                    return NULL;
                }
                int e2 = (int) strlen(str);
                taulu[i+1] = malloc((e2+1) * sizeof(char));
                if (taulu[i+1] == NULL){
                    return NULL;
                }
                strcpy(taulu[i+1], str);
                taulu[i+2] = NULL;
        }
        
    }
    return taulu;
}

void print_split_string(char **split_string) {
    if(split_string == NULL) return;
    for(int i = 0; split_string[i] != NULL; i++){
        printf("%s\n", split_string[i]);
    }
}

void free_split_string(char **split_string) {
    if(split_string == NULL) return;
    for (int i = 0; split_string[i] != NULL; i++)
        {
            free(split_string[i]);
        }
    free(split_string);
}

void main(){
    char * cee[] = {"Merkkijono","joka","pilkotaan",NULL};
    const char * dee = "er";
    const char * bee = "aaerteteerqwerty";
    print_split_string(cee);


    char ** spl = split_string(bee, dee);
    print_split_string(spl);
    free_split_string(spl);

}



