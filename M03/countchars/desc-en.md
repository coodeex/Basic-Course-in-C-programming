### Programming task 3.5: Count chars (20 pts)

**This task handles an array that consists of characters. The end of
the array is marked with value 0.**

You will implement two functions, of which both will yield part of the
points in the task.

**(a):** Implement function defined as `unsigned int arraylen(const
char *array)`.  The function gets argument *array*. You will not know
the length of the array at the time of calling the function, but you
will know that it ends in value 0. The function should return the
number of members in the array, not including the ending 0 value.

**(b):** Implement function defined as `void countchars(const
char *array, unsigned int *counts)`.
Function gets argument *array*, that functions as above described.
The second parameter *counts* refers to an array with 256 members, to
which you should count each of the characters in *array*. Remember
that char type consists of 8 bits, so the table can fit all possible
char values.
For example, if *array* is
`[ 'a','b','r','a','c','a','d','a','b','r','a',0 ]`, then
`counts['a']` gets 5 as its value, and `counts['b']` gets 2 as its value.
Note that for example character 'a' os just one way to represent
integer (with decimal representation 97 based on ASCII table). You can
assume that the *counts* array is initialized with zeros by the
calling function.

You can use the following program to test your functions. Add the
function implementations in front of the below code.

    void printcounts(int min, int max, const unsigned int *counts) {
        for (int i = min; i <= max; i++) {
	        printf("%c: %u  ---  ", i, counts[i]);
	        if ((i - min + 1) % 6 == 0)
	            printf("\n");
        } 
    }

    void printarray(const char *array) {
        printf("{ ");
        while (*array) {
	        printf("'%c',", *array);
	        array++;
        }
        printf("0 }");
    }

    int main()
    {
         unsigned int counts[256] = { 0 };

         char sample[] = { 'a','b','r','a','c','a','d','a','b','r','a',0 };

         printf("%s, length: %u\n", sample, arraylen(sample));
         countchars(sample, counts);
         printcounts('a', 'z', counts);

        return 0;
	}
