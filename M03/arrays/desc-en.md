### Programming task 3.4: Arrays (30 pts)

**In this task, we continue to learn more about arrays and pointers. Complete
  functions need to be implemented in this task.**

In this task, implement the following two functions.

**1)** You should implement function `int array_sum(int *array, int count)` that 
gets a pointer to the beginning of array of integers in consecutive slots in memory, 
and calculates the sum of the integers. The number of integers to be counted is 
given in parameter 'count'. The 'sum' is returned as the return value of the function.

For example, the following code:

    int valarray[] = { 10, 100, 1000 };
    int ret = array_sum(valarray, 3);

should set ret to 1110.
        
**2)** Implement function `int array_reader(int *vals, int n)` that reads integer 
values using scanf into pre-allocated array ('vals'). The numbers read from input 
are separated with whitespace (space, tab, newline,...) that is the default field 
separator for scanf function, i.e., you should be able to use the basic scanf format 
string for decimal numbers. Parameter 'n' gives the maximum length of the array, 
and the maximum number of values to be read. 

If user does not give a valid integer (as can be seen from return value of scanf), 
the array ends, even if the maximum size was not yet reached. The function returns 
the final size of the array at the end, which can be smaller that the incoming 'n' 
parameter, if the user finished the input with non-valid integer.

Below is an example how this function can be tested:

    int array[10];
    int n = array_reader(array, 10);
    printf("%d numbers read\n", n);
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

For example, the following input should cause the first four array elements to become 
5, 8, 2, and 7, and then terminate because the fifth field read is not a decimal number:

5 8 2 7 -

Implement therefore '.c' - file for the above two functions, as well as their main 
function to test. For both properly operating function you will get 15 points (no warnings
must be present).
