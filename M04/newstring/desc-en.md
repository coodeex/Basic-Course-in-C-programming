### Programming task 4.5: New string (25 pts)

**Objective:** How do the string functions really work? This exercise might help 
understanding them.

For this task we assume a new kind of string that does not end at `'\0'` like the 
normal strings. Instead, the new string terminator is question mark '?'. Therefore we 
need to re-implement some of the common string processing functions following the
new string specifications.

Note that the above-discussed string functions defined in string.h **do not work 
with this exercise!** The char arrays given to the functions do not necessary 
contain the usual `'\0'` terminator.

### a) Print string

Implement function `void qstr_print(const char *s)` that outputs string s until the 
first instance of the string terminating '?'. However, the hash character should
not be printed. For example, if the function gets the following standard C string 
as input:

char *str = "Auto ajoi?kilparataa";

it will output:

Auto ajoi

### b) String length

Implement function `unsigned int qstr_length(const char *s)` that returns the number 
of characters in array s before the terminating '?'. The hash character should not 
be included in count.

For example, if the function gets the following standard C string 
as input:

char *str = "Auto ajoi?kilparataa";

it will return:

9

### c) String concatenation

Implement function `int qstr_cat(char *dst, const char *src)`, that appends a copy of 
the string *src* to the *dst* string. The function should return the number of
the characters in the final *dst* string. The function should copy characters
only until the first '?' character and after copying the destination string
must also terminate with '?'. (Hint: you can test that the destination string looks correct
by using the qstr_print function)

For example, if the function gets the following strings as parameters:

char dst[50] = "Auto ajoi?";
char *src = " katua pitkin? lujaa";

it should return:

22

and the string *dst* should look like this:

Auto ajoi katua pitkin?

### d) Substring search

Implement function `const char *qstr_strstr(const char *str1, const char *str2)`
that searches for the substring *str2* from the string *str1*. The function 
should return a pointer to the first occurance of *str2* in *str1*. If the substring
isn't found, the function should return NULL (note that NULL is defined in **stddef.h** 
header). Remember that the function should only search until the first '?' character.

For example, if the function gets the following strings as parameters:

char *str1 = "Auto ajoi katua pitkin?";
char *str2 = "katu?";

it should return a pointer that points to the first character of the word `katua` where 
the first occurance of the substring `katu` begins.
```
