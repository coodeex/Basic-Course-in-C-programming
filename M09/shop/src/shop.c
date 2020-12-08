#include "shop.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <string.h>

int write_binary(const char* filename, const Product* shop)
{
	FILE *f = fopen(filename, "wb");
    if(!f) return 1;

    for(;shop->name[0] != '\0';){
        fwrite(shop, sizeof(Product), 1, f);
        shop++;
    }

    fclose(f);
    return 0;
}

Product* read_binary(const char* filename)
{
    Product *tul = NULL;
    FILE *f = fopen(filename, "rb");
    
    if(!f){ return tul;
    }
	
    tul = malloc(sizeof(Product)+10);
    tul[0].name[0]='\0';

    for(int i = 0; !feof(f);){
        if(fread(&tul[i], sizeof(Product), 1, f) == 1){     //mitä vi
            i++;
            tul=realloc(tul,sizeof(Product)*(i+1));
            tul[i].name[0]='\0';
        }
    }
    fclose(f);
    return tul;
}

int write_plaintext(const char* filename, const Product* shop)
{
	FILE *f = fopen(filename, "wb");
    if(!f) return 1;
    for(;shop->name[0] != '\n';shop++){
        fprintf(f, "%s %f %d\n", shop->name, shop->price, shop->in_stock);
    }
    fclose(f);
    return 0;
}

Product* read_plaintext(const char* filename)
{
	Product *tul = NULL;
    
    FILE *f = fopen(filename, "r");
    if(!f) return tul;
    tul = malloc(10+sizeof(Product));
    tul[0].name[0] = '\0';
    for(int i = 0;!feof(f);){
        if(fscanf(f,"%s %f %d\n", tul[i].name, &tul[i].price, &tul[i].in_stock) ==3){
            i++;
            tul = realloc(tul, sizeof(Product)*(1+i));
            tul[i].name[0]='\0';
        }
        else{
            tul[i].name[0]='\0';
        }
    }
    fclose(f);
    return tul;
}

void main(){
    
}