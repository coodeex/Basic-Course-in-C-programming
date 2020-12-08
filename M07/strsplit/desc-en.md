### Programming task 7.4: Split string {.nonumber .csRunDiv .task_alt}

In this exercise you will split string based on another string.
For example `"String to be split"`, which is split by `" "`, will
result in an array containing the split parts: `["String","to","be","split",NULL]`.
The resulting arrays will always end with a NULL pointer.

The exercise has two parts:

a) Implement a function `void print_split_string(char** split_string)`, which
prints a split string, each part on its own line. For example when calling
the function for a split string `["String","to","be","split",NULL]`, 
the function prints:

String
to
be
split

b) Implement functions 
    - `char** split_string(const char* str, const char* split)`
    
        The function splits a string in the
        aforementioned way and returns the parts in a dynamically reserved array.
        Parameters are as follows:

        - `const char* str`, the string to be split
        - `const char* split`, the string used to split `str`,
        for example `"One. .more. .test. .for. .string. .splitting."` and `". ."`, when
        the result is an array consisting of the following pieces:
        `["One","more","test","for","string","splitting",NULL]`
        
        Also, the pieces need to have their memory dynamically reserved and they need
        to be copied to the array. The function `strstr` may be helpful in this exercise.
        
    - `free_split_string(char** split_string)`
        
        The function frees the memory for the split string array.


