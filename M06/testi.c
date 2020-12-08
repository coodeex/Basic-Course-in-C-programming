//
#include <stdio.h>
#include <string.h>

// BYCODEBEGIN
// Define the missing structure here
struct Ship {
    char *name;
    float weight;
    const char *cargo[10];
};



// Define function clear_cargo here
void clear_cargo(struct Ship *r){
    for(int i = 0; r->cargo[i] != 0; i++){
        r->cargo[i] = NULL;
    }
}
// Define function add_cargo here
void add_cargo(struct Ship *r, char *str){
    int i = 0;
    for(; r->cargo[i] != 0; i++){
        //nii
    }
    r->cargo[i] = str;
}
// BYCODEEND

int main(void)
{
    struct Ship vessel_1 = { "Tanker", 100000, { NULL } };

    clear_cargo(&vessel_1);
    add_cargo(&vessel_1, "Gasoline");
    add_cargo(&vessel_1, "Oil");
    add_cargo(&vessel_1, "Diesel");

   /* struct Ship vessel_2;
    vessel_2.name = "Fun boat";
    vessel_2.weight = 1.25;
    clear_cargo(&vessel_2);
    add_cargo(&vessel_2, "Food basket");
    add_cargo(&vessel_2, "Sunscreen");
    add_cargo(&vessel_2, "Very good lemonade");
    add_cargo(&vessel_2, "Frankfurters");

    struct Ship ships[2];
    ships[0] = vessel_1;
    ships[1] = vessel_2;
*/
  /*  for (int i = 0; i < 2; i++) {
	    printf("Name: %s  / Weight %.2f tonnes\n", ships[i].name, ships[i].weight);
	    printf("Cargo:\n");
	    for (int j = 0; ships[i].cargo[j] != NULL; j++) {
	        printf("* %s\n", ships[i].cargo[j]);
	    }
	    printf("----------\n");
    }*/
}


