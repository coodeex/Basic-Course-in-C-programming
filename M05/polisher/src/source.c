
#include "source.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//#include "testfile.c"

/* Remove C comments from the program stored in memory block <input>.
 * Returns pointer to code after removal of comments.
 * Calling code is responsible of freeing only the memory block returned by
 * the function.
 */
char *delete_comments(char *input)
{

    char *super = malloc(10000 * sizeof(char));
    memset(super,0,10000);
    if(super == NULL){
        return input;
    }
    char *ogsuper = super;
    char *oginput = input;
    while(*input){
        if(*input == '/' && *(input+1) == '*'){ // löytyy nää
            input++;
            input++;
                while(*input != '*' || *(input+1)!='/'){
                    input++;
            }
            input++;
            input++;
        }
        else if(*input == '/' && *(input+1) == '/'){
            while(*input != '\n'){
                input++;
            }
            input++;
        }
        *super = *input;
        input++;
        super++;
        continue;

    }

    free(oginput);
    return ogsuper;
}

int main(void) {
    //char * aab = malloc(100*sizeof(char));
    //delete_comments(*('testfile.c'));
    return 0;

}