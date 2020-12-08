#include "source.h"
#include "string.h"
#include "stdio.h"


int num_substr(const char *str, const char *sub) {
    int num = 0;
    while(*str != '\0'){
        char *ptr = strstr(str, sub);

        if(ptr!=NULL){
            str = ptr + 1;
            num++;
        }
        else{
            str++;
        }
        //printf("%s", str);
    }
    return num;
}

void main() {
    printf("%d", num_substr("two beniz twotwo kikels two.", "two"));
}