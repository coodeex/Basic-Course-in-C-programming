#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct character{
    char* name;
    int hp;
    char* weapon;
    int weapondamage;
    int xp;
    int index; //just for testing
};

int compareChar(const void *s1, const void *s2)
        {
            struct character *e1 = (struct character *)s1;
            struct character *e2 = (struct character *)s2;
            return e2->xp - e1->xp;
        }

int compareChar2(const void *s1, const void *s2)
        {
            struct character *e1 = (struct character *)s1;
            if(e1->hp <= 0){
                return 1;
            }else{
                return 0;
            }
        }

struct character *doSomething(char* inp, struct character *array){
    
    if(inp[0] == 'A'){
        char a;
        // initializing variables with some faulty values, so we can check in the 
        // next if-statement that the variables are changed by the user input. 
        char name[80] = "0";
        char weapon[80] = "0";
        int hp = -1;
        int weapondamage = -1;
        int xpee;
        //sscanf(inp, "%c %s %d %s %d", &a, name, &hp, weapon, &weapondamage);
        sscanf(inp, "%c %s %d %s %d %d", &a, name, &hp, weapon, &weapondamage, &xpee);
        
        if(name[0] == '0' || weapon[0] == '0' || hp < 0 || weapondamage < 0){
            printf("Something went wrong. Check that your input is typed correctly.\n");
            return array;
        }

        int i;
        // Increase i until we arrive at array member with NULL name
        for (i = 0; array[i].name != NULL; i++);
        //printf("\nvalue of i is:  %d\n\n", i);
        struct character *newarray = realloc(array, sizeof(struct character) * (i + 2));
        if (newarray == NULL) {
            return array; // return, because allocating memory did not work
        }

        // Allocate memory for the name, and copy the name into right location
        newarray[i].name = malloc(strlen(name) + 1);
        if (newarray[i].name == NULL) {
           free(newarray);  // because it was already allocated
            return array;
        }
        strcpy(newarray[i].name, name);

        // Allocate memory for the weapon name, and copy the weapon name into right location
        newarray[i].weapon = malloc(strlen(weapon) + 1);
        if (newarray[i].weapon == NULL) {
            free(newarray[i].name); // because it was already allocated
            free(newarray);         // because it was already allocated
            return array;
        }
        strcpy(newarray[i].weapon, weapon);
        newarray[i].hp = hp;
        newarray[i].weapondamage = weapondamage;
        //newarray[i].xp = 0;
        newarray[i].xp = xpee;

        newarray[i].index = i;
        newarray[i+1].name = NULL; // Set the new NULL member at end

        printf("nimi: %s indeksi: %d\n", newarray[i].name, newarray[i].index); // A Bilbo 25 Dagger 8
        
        //printf("i=%d, eka %d toka %d NULL on %d\n", i,newarray[0].hp, newarray[1].hp, i+1);
        array = newarray;
        //if(array[i].name == NULL)printf("\narray[%d].name is NULL\n\n", i);
        //if(array[i+1].name == NULL)printf("\narray[%d].name is NULL\n\n", i+1);
        return array;
    }
    
    else if(inp[0] == 'L'){
        struct character *a = array; // a will be a sorted array
        int i;
        // Increase i until we arrive at array member with NULL name
        for (i = 0; array[i].name != NULL; i++);
        qsort(a, i, sizeof(struct character), compareChar); // sorts by xp points
        qsort(a, i, sizeof(struct character), compareChar2);// puts died characters to the end
        
        printf("\nAll characters in the descending order of xp, except that already dead characters are in the end:\n");
        for(int i = 0;array[i].name!=NULL;i++){
            printf("Name: %s, HP: %d, Weapon: %s, indeksi: %d XP: %d\n", a[i].name, a[i].hp, a[i].weapon, a[i].index, a[i].xp);
        }
        return array;
    }

    else if(inp[0] == 'W'){
        FILE *fp = fopen("filename.txt", "w");
        if (!fp) {
            fprintf(stderr, "Opening a file failed\n");
            return array;
        }

        int i;
        // Increase i until we arrive at array member with NULL name
        for (i = 0; array[i].name != NULL; i++);
        //fprintf(fp,"%d\n",i);

        for (int j = 0; j<i; j++){

            fprintf(fp, "%s %d %s %d %d\n", array[j].name, array[j].hp, array[j].weapon, array[j].weapondamage, array[j].xp);
        }
        fprintf(fp,"0");

        /*int i;
        // Increase i until we arrive at array member with NULL name
        for (i = 0; array[i].name != NULL; i++);

        fwrite(array, sizeof(struct character), i, fp);
        if (ferror(fp)){
            fprintf(stderr, "Something went wrong\n");
            return array;
        }*/
        fclose(fp);
        return array - i;
    }

    else if(inp[0] == 'O'){

        struct character *a = malloc(sizeof(struct character));
        if (array == NULL) {
            printf("Copying failed\n");
            return array;
        }

        FILE *fp = fopen("filename.txt", "r");
        if(!fp){ 
            free(a);
            return array;
        }


        char aa;
        // initializing variables with some faulty values, so we can check in the 
        // next if-statement that the variables are changed by the user input. 
        char name[80] = "0";
        char weapon[80] = "0";
        int hp = -1;
        int weapondamage = -1;
        int xpee;

        while (fscanf(fp,"%c %s %d %s %d %d", &aa, name, &hp, weapon, &weapondamage, &xpee)>1) {
            if(name[0] == '0' || weapon[0] == '0' || hp < 0 || weapondamage < 0){
                printf("File content was incompatible.\n");
                return array;
            }


            strcpy(name,"0");
            strcpy(weapon,"0");
            hp = -1;
            weapondamage = -1;
            xpee=0;

        }
        return a;

        /*struct character *a = malloc(sizeof(struct character)*10); 
        if (a == NULL) {
            return array;
        }
        FILE *fp = fopen("filename.txt", "rb");
        if(!fp){ 
            free(a);
            return array;
        }
        a[0].name = NULL;
        for(int i = 0; !feof(fp);){
            if(fread(&a[i], sizeof(struct character), 1, fp) == 1){
                
                a = realloc(a, sizeof(struct character)*(i+2));
                if (a == NULL) {
                    return array;
                }
                a[i+1].name = NULL;
                i++;
            }
        }
        fclose(fp);
        array = a;
        return array;*/
    }

    else if(inp[0] == 'Q'){
        printf("exitted\n");
        //free?
        return NULL;
    }

    else{
        printf("Something went wrong. Check that your input is typed correctly.\n");
        return array;
    }
}



int main(void){
    struct character *array = malloc(sizeof(struct character)); // Initializing an array for character structs
    if (array == NULL) {
        printf("Starting failed\n");
        return -1;
    }
    array[0].name = NULL;
    /*array=doSomething("A Opena 1 ase 5 5 9", array);
    array=doSomething("A 1jaakob 8 ase 5 8", array);
    array=doSomething("A 20juuso 0 ase 5 6", array);
    array=doSomething("A 3viljami 12 ase 5 9", array);
    array=doSomething("A 4margareetta 5 ase 5 2", array);
    array=doSomething("A 50vilijoncca 0 ase 5 4", array);
    array=doSomething("A 6ressu 2 ase 5 100", array);
    array=doSomething("A 70johannes 0 ase 5 80", array);
    array=doSomething("A 8pajeet 2 ase 5 50", array);*/
    array=doSomething("A 90kepantti 0 ase 5 30", array);
    while(array != NULL){ // Array is set to NULL when the player wants to quit the game.
        printf("Next move:\n");
        char input[80];
        fgets(input, 80, stdin);
        array = doSomething(input, array);
        if(array!=NULL){ //testing:
            /*if(array[0].name == NULL)printf("\narray[%d].name is NULL\n\n", 0);
            if(array[1].name == NULL)printf("\narray[%d].name is NULL\n\n", 1);
            if(array[2].name == NULL)printf("\narray[%d].name is NULL\n\n", 2);
            */
        }
    }
    return 0;
}
