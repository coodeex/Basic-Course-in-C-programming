### Programming task 5.3: Dynamic arrays (30 pts)

**In this task, we practice dynamic memory allocation and extending arrays**

Two functions need to be implemented in this task. To collect points, some kind 
of implementation must exist for both functions. Remember, valgrind errors must 
not be present to get full points.

1) Implement function `int *create_dyn_array(unsigned int n)` that allocates an int array for n integers. 
n is given as argument to the function when it is called. After allocating the array,
the function should read the given number of integers to the array from user, using 
the **scanf** function. After the right amount of integers have been read, the function
returns pointer to the dynamically allocated array.

2) Implement function `int *add_dyn_array(int *arr, unsigned int num, int newval)`
that adds a single integer to the existing dynamically allocated array of integers 
(arr). The length of the existing array is num, and the new integer to be added is 
given in parameter newval. You'll need to ensure that array is extended to hold the 
additional integer. Check that the function works correctly when called several
consecutive times.
