// C Programming course project
// Olympics
// By Veera Ihalainen

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    char *name; //name of the nation max. 21 characters
    unsigned int gold;  // number of gold medals
    unsigned int silver;   // number of silver medals
    unsigned int bronze;  // number of bronze medals
} Nation;

typedef struct {
    Nation *countries; //pointer to the array of Nation structures
    unsigned count; // number of countries in the array
} Info;

// Adds a nation to the database
// run by inputting the letter "A" and the name of the nation that is wanted to add
// gets the pointer to the beginning of the Nation array, name of the new nation and length of the array as parameters
Nation *add_nation(Info *data, char str[80]){
    
    char name[20];

    if (sscanf(str, "A %s", name) != 1){
        printf("Error");
    }
    printf("Sscanf toimi\n");

    // making a longer dummy list
    Nation *dummy = realloc(data->countries, sizeof(Nation) * (data->count + 2));
    printf("Realloc\n");
    if (dummy == NULL){
        return NULL;
    }

    dummy[data->count].name = malloc(strlen(name) + 1);
    if (dummy[data->count].name == NULL){
        free(dummy);
        return data->countries;
    }



    strcpy(dummy[data->count].name, name);
    dummy[data->count].gold = 0;
    dummy[data->count].silver = 0;
    dummy[data->count].bronze = 0;

    dummy[data->count + 1].name = NULL;
    printf("%s was added to the database\n", name);

    return dummy;
}

// Adds the given amount of medals to the given country
// run by inputting "M (name_of_nation) (gold) (silver) (bronze)" 
// gets an array of strings(input[1] = name, [2]=gold, [3]= silver, [4]= bronze) and the pointer to the array of nations as parameters
// checks that items 2-4 can be interpreted as numbers, else it prints an error message
// Finds the correctly named item from the array of nations and adds the gived amounts of medals to the existing numbers
void update_medals(Info *data, char str[80]){
    char option;
    char name[20];
    int gold;
    int silver;
    int bronze;

    sscanf(str, "%c %s %d %d %d", &option, name, &gold, &silver, &bronze);

    for(unsigned int i = 0; i < data->count; i++){

        if (strcmp(name, data->countries[i].name)== 0){

            // Nations can't have negative number of medals
            if (data->countries->gold + gold < 0){
                gold = -1 * data->countries->gold;
            }
            if (data->countries[i].silver + silver < 0){
                silver = -1 * data->countries->silver;
            }
            if (data->countries->bronze + bronze < 0){
                bronze = -1 * data->countries->bronze;
            }

            data->countries[i].gold += gold;
            data->countries[i].silver += silver;
            data->countries[i].bronze += bronze;
            //printf("%d %d %d\n", data.countries->gold, data.countries->silver, data.countries->bronze);
            break;
        }
        if (i == data->count - 1 && strcmp(name, data->countries[i].name)== 0){
            printf("Nation was not found from the data base\n");
        }
    }
}

// Sorts the given array of Nation struct items
// From most gold medals to least
// If number of gold medals is the same, first silver medals are considered then bronze
//Nation* sortfunc (Nation *orig, const int count) {

    /*if ((((const Nation*)b)->gold - ((const Nation*)a)->gold) != 0){
        return ((const Nation*)b)->gold - ((const Nation*)a)->gold;
    }
    else if ((((const Nation*)b)->silver - ((const Nation*)a)->silver) != 0)
    {
       return (((const Nation*)b)->silver - ((const Nation*)a)->silver);
    }
    else{
       return (((const Nation*)b)->bronze - ((const Nation*)a)->bronze);
    }*/
//}
    

// Prints the current medal table, i.e. all nations in the memory along with their medal counts
// Sorts the array before printing by number of medals (first gold then silver then bronze)
void print_medal_table(Info *data){

    //qsort(orig - 1, count, sizeof(Nation*), cmpfunc);
    /*Nation *ret = malloc(count * sizeof(Nation));

    for (int rnum = 0; rnum < count; rnum++){
        for (int onum = 0; onum < count; onum++){
            if (data->countries[onum]gold == data.countries[onum + 1]->gold){

            }
        }
    }*/

    int i = 0;
    while(i < data->count){
        printf("%10s %2d %2d %2d\n", data->countries[i].name, data->countries[i].gold, data->countries[i].silver, data->countries[i].bronze);
        i++;
    }
}

// Writes the given array of Nations to a file with the given name
// Gets the pointer to the given array and a string (name of file) as parameters
// All items are written to the file the same way as print_medal_table prints them to stdout
int write_file(const char str[80], Info *data){

    char option;
    char *filename = NULL;
    sscanf(str, "%c %s", &option, filename);

    FILE *f = fopen(filename, "w");

    if (!f) {
        return 1;
    }

    fprintf(f, "     Olympics Medal Analytics\n");
    int i = 0;
    while (data->countries[i].name[0] != '\0'){
        fprintf(f, "%10s %2d %2d %2d\n", data->countries[i].name, data->countries[i].gold, data->countries[i].silver, data->countries[i].bronze);
        i++;
    }

    fclose(f);
    printf("Medal data was saved to file %s\n", filename);
    return 0;
}

// Reads the given file as a Nation array and replaces the current array
// 
Info *read_table(const char str[80]){

    char option;
    char *filename = NULL;
    sscanf(str, "%c %s", &option, filename);

    FILE * file= fopen(filename, "r"); // opening file to be read


    Nation* obj = malloc(sizeof(Nation *)); // creating new array
    int i = 0;
    char line[80];
    fgets(line, 80, file);

    while (fgets(line, 80, file) != NULL) {
        obj = realloc(obj, sizeof(Nation)*(2+i)); // allocating memory for a new item
        if (sscanf(line,"%s %d %d %d\n", obj[i].name,&obj[i].gold,&obj[i].silver, &obj[i].bronze) == EOF){ // scanning lines from the file, if line has wrong format the scanning is ended
            i--;
            break;
        }
        i++;
    }

    obj[i].name[0] = '\0';

    Info *ret = malloc(sizeof(Info));
    ret->countries = obj;
    ret->count = i;

    fclose(file);
    printf("New medal data was uploaded\n");
    return ret;
}

// frees memory allocated to the countries array
void prog_exit(Info *arr){
    free(arr->countries);
    printf("Exiting program");
}

int main(void){
    printf("Olympics Medal Analytics\nInstructions for input: \n'A' 'country' to add a nation to the database \n'M nation gold silver bronze'\n");
    printf("Input:\n");

    Info *data = malloc(sizeof(Info));
    data->countries = malloc(sizeof(Nation));
    data->count = 0;
    data->countries[0].name = NULL;

    int success = 1;

    char str[80];

    while (success == 1){
        fgets(str, 80, stdin);
        // switch and case for finding the right function to run
        switch(str[0]){
            case 'A':
                data->countries = add_nation(data, str);
                data->count++;
                break;

            case 'M':
                update_medals(data, str);
                break;

            case 'L':
                print_medal_table(data);
                break;

            case 'W':
                write_file(str, data);
                break;
            
            case 'O':
                data = read_table(str);
                break;

            case 'Q':
                success = 0;
                break;

            default:
                printf("Invalid input!\n");
                break;
        }
    }
    prog_exit(data);
    return 0;
}