#include "filebasics.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include <string.h>

/* Print give file <filename> to the standard output stream.
 * Return number of characters printed, -1 if file opening fails.
 */
int print_file_and_count(const char *filename)
{
    int i = 0;

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Could not open file\n");
        return -1;
    }
    char c = fgetc(fp); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fp); 
        i++;
    } 
    fclose(fp); 
    return i;
}

/* Compare two files. The function should return the first lines that differ
 * in the two files, concatenated together, separated by four dashes, on
 * different lines. If the files are equal, NULL is returned. 
 * Function stops immediately, if either one of the files end and returns NULL.
 * You can assume that lines are not longer than 1000 characters.
 */
char *difference(const char *file1, const char *file2)//menee ihan metsään
{
    
    char *paluu = NULL;
    FILE *f1 = fopen(file1, "r");
    if(f1 == NULL) {
        //perror("Error opening file");
        return NULL;
    }
    FILE *f2 = fopen(file2, "r");
    if(f2 == NULL) {
        //perror("Error opening file");
        return NULL;
    }
    char *c1 = malloc(1000 * sizeof(char));
    char *c2 = malloc(1000 * sizeof(char));
    unsigned int maks = 1000;
    //int error = 0, pos = 0, line = 1; 

    while(!feof(f1) && !feof(f2)){
        //pos++; 
        if (fgets(c1, maks, f1) && fgets(c2, maks, f2)){
            if(strcmp(c1, c2) != 0){
                int rr = strlen(c1) + strlen(c2) + 6;
                paluu = malloc(rr);
                strcpy(paluu, c1);
                strcat(paluu, "----\n");
                strcat(paluu, c2);
            break;
            }
        }
        { 
        //line++; 
            //pos = 0; 
        } 
    
    /*if (c1 != c2) 
        { 
            char *s1=fgets(s1,1001, f1);
            char *s2=fgets(s2,1001, f2);
            
            error++; 
            printf("Line Number : %d \tError"
               " Position : %d \n", line, pos); 
            paluu = ("%s\n----\n%s",s1, s2);//fgets((f2+ftell(f2)),1001, f2)); //"%s\n----\n%s",??
            fclose(f1);
            fclose(f2);
            return paluu;
        } */
    }

    fclose(f1);
    fclose(f2);
    free(c1);
    free(c2);
    return paluu;
}



int main(void)
{
    printf("--- Printing file:\n");
    int t = print_file_and_count("testfile.c");
    if(t<0)
        printf("Opening failed!\n");

    printf("--- Printed %d characters\n", t);

    char* diff = difference("testfile.c", "testfile2.c");
    printf("\n--- Difference:\n");
    printf("%s", diff);

    free(diff);

    return 0;
}
