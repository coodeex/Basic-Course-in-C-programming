#include "book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

int init_book(struct book *p_book, const char *p_id, const char *p_title, const char * p_author, struct date release)
{
    if(strlen(p_id) > 9){
        return 0;
    }
    //struct book *newbook = (p_id, p_title, p_author, release);
	strcpy(p_book->id, p_id);
    p_book->title = malloc(strlen(p_title)+1);
    if (p_book->title == NULL) {
            free(p_book);  // because it was already allocated
            return 0;
    }
    p_book->author = malloc(strlen(p_author)+1);
    if (p_book->author == NULL) {
            free(p_book);  // because it was already allocated
            return 0;
    }
    strcpy(p_book->title, p_title);
    strcpy(p_book->author, p_author);
    p_book->release_date = release;


    
    return 1;
}

struct book *add_to_collection(struct book *collection, unsigned int size, struct book new_book)
{
    /*int i = 0;
	for(; collection[i].id != NULL; i++);   */

    struct book *newcoll = realloc(collection, sizeof(struct book) * (size + 5));
    if (newcoll == NULL) {
        return NULL; // allocating memory did not work
    }
    init_book(newcoll+size,new_book.id,new_book.title,new_book.author,new_book.release_date);
    return newcoll;
    
}

void main() {
    printf("%d", 1);
}