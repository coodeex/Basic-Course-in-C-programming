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
};

int compareChar(const void *s1, const void *s2)
        {
            struct character *e1 = (struct character *)s1;
            struct character *e2 = (struct character *)s2;
            //if(e1->name==NULL || e2->name==NULL) return 0;
            if(e1->name==NULL) {
                return 1;
            }else if(e2->name==NULL) {
                return 0;
            }else {
                return e2->xp - e1->xp;
            }
        }
int compareChar2(const void *s1, const void *s2)
        {
            struct character *e1 = (struct character *)s1;
            struct character *e2 = (struct character *)s2;
            //if(e1->name==NULL || e2->name==NULL) return 0;
            if(e1->name==NULL) {
                return 1;
            }else if(e2->name==NULL) {
                return 0;
            }else if(e1->hp <= 0) {
                return 1;
            }else {
                return 0;
            }
        }

void freeArray(struct character *a) {
    for(int i = 0;a[i].name != NULL; i++) {
        free(a[i].name);
        free(a[i].weapon);
    }
    free(a);
}

// If something goes wrong this will return the original array
struct character *doSomething(char* inp, struct character *array) {
    
    if(inp[0] == 'A') {
        char name[80], weapon[80];
        int hp, weapondamage;
        //sscanf(inp, "%c %s %d %s %d", &a, name, &hp, weapon, &weapondamage);
        if(sscanf(inp, "A %s %d %s %d", name, &hp, weapon, &weapondamage) != 4) {
            printf("Something went wrong. Check that your input is typed correctly.\n");
            return array;
        }
        
        if(hp < 0 || weapondamage < 0) {
            printf("Something went wrong. Check that your input is typed correctly.\n");
            return array;
        }


        int n;
        for(n = 0; array[n].name != NULL && strcmp(array[n].name, name) != 0; n++);
        if(array[n].name != NULL) {
            printf("Name is taken. Try another one, please\n");
            return array;
        }

        int i;
        // Increase i until we arrive at array member with NULL name
        for (i = 0; array[i].name != NULL; i++);
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

        // Copy other values
        newarray[i].hp = hp;
        newarray[i].weapondamage = weapondamage;
        newarray[i].xp = 0;
        //newarray[i].xp = xp;

        newarray[i+1].name = NULL; // Set the new NULL member at end

        printf("Created a new player named \"%s\"\n", newarray[i].name);
        return newarray;
    }
    
    else if(inp[0] == 'H') {
        char attacker[80];
        char defender[80];
        if(sscanf(inp, "H %s %s", attacker, defender) != 2) {
            printf("Something went wrong. Check that your input is typed correctly.\n");
            return array;
        }
        
        int a, d;
        for(a = 0; array[a].name != NULL && strcmp(array[a].name, attacker) != 0; a++);

        for(d = 0; array[d].name != NULL && strcmp(array[d].name, defender) != 0; d++);

        if(array[a].name == NULL && array[d].name == NULL) {
            printf("Attacker's name and defender's name are invalid\n");
            return array;
        }

        if(array[a].name == NULL) {
            printf("Attacker's name is invalid\n");
            return array;
        }

        if(array[d].name == NULL) {
            printf("Defender's name is invalid\n");
            return array;
        }
        
        if(array[a].hp == 0) {
            printf("Dead people can not attack\n");
            return array;
        }

        if(array[d].hp == 0) {
            printf("It is not possible to attack dead people\n");
            return array;
        }

        printf("%s attacked against %s\n", array[a].name, array[d].name);
        int damage;
        damage = rand()%(array[a].weapondamage+1);    // damage is something between 0 and wepondamage
        if(damage == array[a].weapondamage) printf("Critical hit!\n");
        array[d].hp -= damage;
        array[a].xp += damage;

        if(array[d].hp<=0) {
            printf("%s died and %s gained %d xp points\n", array[d].name, array[a].name, damage + array[d].hp + 10);
            array[a].xp +=array[d].hp + 10;
            array[d].hp = 0;
        }else {
            printf("%s lost %d hitpoints and %s gained the same amount of xp points\n", array[d].name, damage, array[a].name);
        }
        return array;
    }
    
    else if(inp[0] == 'L') {
        struct character *a = array; // a will be a sorted array
        int i;
        // Increase i until we arrive at array member with NULL name
        for (i = 0; array[i].name != NULL; i++);
        qsort(a, i, sizeof(struct character), compareChar); // Sort by xp points
        qsort(a, i, sizeof(struct character), compareChar2);// Put died characters to the end
        
        if(a[0].name==NULL) {
            printf("The list of players is empty\n");
            return array;
        }
        printf("\nAll characters in the descending order of xp, except that already dead characters are in the end:\n");
        for(int i = 0;array[i].name!=NULL;i++){
            printf("Name: %s, HP: %d, Weapon: %s, Weapondamage: %d XP: %d\n", a[i].name, a[i].hp, a[i].weapon, a[i].weapondamage, a[i].xp);
        }
        return array;
    }

    else if(inp[0] == 'W'){
        char w;
        char filename[80];
        if(sscanf(inp, "%c %s", &w, filename) != 2){
            printf("Something went wrong. Check that your input is typed correctly.\n");
            return array;
        }

        FILE *fp = fopen(filename, "w");
        if (!fp) {
            fprintf(stderr, "Opening a file failed\n");
            return array;
        }


        int i;
        // Increase i until we arrive at array member with NULL name
        for (i = 0; array[i].name != NULL; i++);
        fprintf(fp,"%d\n",i);

        // Print information of the array into a file
        for (int j = 0; j<i; j++){
            fprintf(fp, "%s %d %s %d %d\n", array[j].name, array[j].hp, array[j].weapon, array[j].weapondamage, array[j].xp);
        }

        printf("Saved the game into a file named \"%s\"\n",filename);
        fclose(fp);
        return array;
    }

    else if(inp[0] == 'O'){
        struct character *a;
        int numberOfchars;
        char filename[80];
        if(sscanf(inp, "O %s", filename) != 1){
            printf("Something went wrong. Check that your input is typed correctly.\n");
            return array;
        }

        FILE* file = fopen(filename, "r");
        if (!file){
            printf("Failed to open the file\n");
            return array;
        }
        if (fscanf(file, "%d\n", &numberOfchars) != 1){
            printf("Failed to read the number of characters\n");
            return array;
        }
        a = malloc(sizeof(struct character)*(numberOfchars + 2));
        if (!a){
            printf("Fail\n");
            return array;
        }

        int i;
        for (i = 0; i < numberOfchars; i++){
            a[i].name = malloc(80*sizeof(char));
            if (a[i].name == NULL) {
                free(a);  // because it was already allocated
                return array;
            }

            a[i].weapon = malloc(80*sizeof(char));
            if (a[i].name == NULL) {
                free(a[i].name); // because it was already allocated
                free(a);         // because it was already allocated
                return array;
            }
            if (fscanf(file, "%s %d %s %d %d\n", a[i].name, &a[i].hp, a[i].weapon, &a[i].weapondamage, &a[i].xp) == 0){
                printf("Error: Unable to read game data\n");
                free(a);
                return array;
            }
        }
        a[i].name = NULL; //i+1
        fclose(file);
        printf("Loaded a game from a file named \"%s\"\n",filename);
        freeArray(array);
        //array=a;
        //return array;
        return a;
        
    }

    else if(inp[0] == 'Q'){
        printf("Exitted\n");
        freeArray(array);
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
    array=doSomething("A 4tyyppi 5 ase 5 2", array);
    array=doSomething("A 50ressu 0 ase 5 4", array);
    array=doSomething("A 6vilijoncca 2 ase 5 100", array);
    array=doSomething("A 70johannes 0 ase 5 80", array);
    array=doSomething("A 8margareetta 2 ase 5 50", array);*/
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
