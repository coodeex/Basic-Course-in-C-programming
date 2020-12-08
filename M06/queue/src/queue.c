#include "queue.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>


int enqueue(struct studentqueue *q, const char *name)
{
    struct studentqueue *new = malloc(sizeof(struct studentqueue));
    char *c = malloc(sizeof(char) * 100);
    if(new == NULL)
    {
        return 0;
    }
    while(q->next != NULL){
        q = q->next;
    }
    q->next = new;
    strcpy(c,name);
    new->name = c;
    new->next = NULL;
    return 1;
}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size)
{
    size_t uu = size;
    if(q->next && strlen(q->next->name) && strlen(q->next->name) < uu){
        strcpy(buffer, (q->next->name));
        struct studentqueue *toDel = q->next;
        q->next = q->next->next;
        free(toDel->name);
        free(toDel);
        return 1;
    }
    else return 0;
}
int main(void)
{
    struct studentqueue q = { NULL, NULL };

    int go_on = 1;
    char buffer[100];
    while(go_on) {
        printf("Enter name of the student (\"-\" will end reading): ");
        scanf("%99s", buffer);
        buffer[99] = 0;
        if (strlen(buffer) > 0 && strcmp(buffer, "-")) {
            go_on = enqueue(&q, buffer);
        } else {
            go_on = 0;
        }
    }

    while(dequeue(&q, buffer, 100)) {
	    printf("Fetched %s from queue\n", buffer);
    }

    return 0;
}


