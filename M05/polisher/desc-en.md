### Programming task 5.5: Code polisher (25 pts)

Implement function `char *delete_comments(char *input)` that removes C comments 
from program stored at *input*. *input* variable points to dynamically allocated memory.
The function returns pointer to the polished program. You may allocate a new memory
block for the output, or modify the content directly in the input buffer.

You'll need to process two types of comments:

  * Traditional block comments delimited by `/*` and `*/`. These comments 
    may span multiple lines. You should remove only characters starting from `/*` 
    and ending to `*/` and for example leave any following newlines untouched.
    
  * Line comments starting with `//` until the newline character. In this case, 
    newline character must also be removed.
    
The function calling *delete_comments* only handles return pointer from *delete_
comments*. It does not allocate memory for any pointers. One way to implement 
*delete_comments* function is to allocate memory for destination string. However, 
if new memory is allocated then it must be released after use.

The zip file linked to at the top of the page contains a testfile.c file for
testing. You can also use other C-files.
