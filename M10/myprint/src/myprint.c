#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>



int myprint(const char *str, ...){
    va_list args;
    va_start(args, str);
    int montako = 0;

    while(*str != '\0'){
        while(*str != '&' && *str != '\0'){
            printf("%c", *str);
            str++;
        }
        if(*str == '&'){
            printf("%d", va_arg(args, int));
            montako++;
            str++;
        }
    }
    va_end(args);


    return montako;
}














/*int myprint(const char *str, ...){
    int m = 0;
    const char * pch;
    va_list args;
    va_start(args, str);
    for(pch = str; *pch != '\0'; pch++){
        while(*pch != '&'){
            //printf("%c", pch);
        }
    }
    va_end(args); 
    return m;
}*/

/*int myprint(char *str, ...){
    //const char *format = *str;
    char *traverse; 
	unsigned int i; 
	char *s; 
	
	//Module 1: Initializing Myprintf's arguments 
	va_list arg; 
	va_start(arg, str); 
	
	for(traverse = str; *traverse != '\0'; traverse++) 
	{ 
		while( *traverse != '&' ) 
		{ 
			putchar(*traverse);
			traverse++; 
		} 
		
		traverse++; 
		
		//Module 2: Fetching and executing arguments
		{ i = va_arg(arg,int);		//Fetch char argument
						putchar(i);
						
						
		}	
	} 
	
	//Module 3: Closing argument list to necessary clean-up
	va_end(arg); 
} */