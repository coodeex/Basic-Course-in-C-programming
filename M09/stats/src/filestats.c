    
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "filestats.h"


/* Returns the line count in given file
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * The number of lines in file. */
int line_count(const char *filename)
{
    FILE* f = fopen(filename, "rb");
    if(!f) return -1;
    int las = 0;
    int data = fgetc(f);
    int juttu = '\n';
    

    for(;data != EOF; data = fgetc(f)){
        juttu = data;
        if(data=='\n') las++;
    }
    if(juttu != '\n') las++;
    fclose(f);
    return las;

}


/* Count the number of words in the file. Word has to include at least one
 * alphabetic character, and words are separated by whitespace.
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * number of words in the file */
int word_count(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if(!f) return -1;
    int data = fgetc(f);
    int las = 0;
    bool onko = false;
    
    for(;data != EOF; data = fgetc(f)){
        if(!onko && isalpha(data)){
            onko = true;
            las++;

        }
        else if(isspace(data) && onko) onko = false;
    }


fclose(f);
return las;
}