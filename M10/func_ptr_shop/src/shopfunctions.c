#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shopfunctions.h"

#include <stdarg.h>

int compareAlpha(const void* a, const void* b)
{
	/*(void)a;
	(void)b;*/
	const Product *joku = a;
	const Product *toine = b;
	return strcmp(joku->name,toine->name);
	
	//return 0;
}

int compareNum(const void* a, const void* b)
{
	/*(void)a;
	(void)b;*/
	const Product *joku = a;
 	const Product *toine = b;
 	if(joku->in_stock == toine -> in_stock){
		return strcmp(joku -> name,toine -> name);
	}
 	else if (joku -> in_stock > toine -> in_stock){ 
		 return -1;
	} else {return 1;}


	//return 0;
}

const Product* findProduct(const Product* p_array, const char* search_key, int (*cmp)(const void*, const void*))
{
	/*(void)p_array;
	(void)search_key;
	(void)cmp;*/

	//int a = 0;
	int s = 0;

	for(int i = 0; p_array[i].name[0] != 0; i++){
		s++;
	}
	
	const Product *pala = bsearch(search_key, p_array,s,sizeof(Product),cmp);
 
	
	return pala;
}

