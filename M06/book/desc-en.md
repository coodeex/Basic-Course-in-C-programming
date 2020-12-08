### Programming task 6.3: Book (25 pts)

**Objective:** Practice use of data structures, as a member of dynamically allocated 
(and re-sized) array.

Implement a simplified database for storing books. Each database record is 
specified as **struct book**, and the database is built as a dynamically allocated 
array, that contains a number of consecutive **struct book** instances in contiguous 
positions in memory that needs to be dynamically allocated. Every time a new element 
is added to the array, it needs to be reallocated to have sufficient space for all 
entries.

**struct book** definition, and the purpose of each field in the structure are defined
in file **book.h**. Pay attention to which structure members are allocated as part 
of the structure definition, and which need to be allocated separately. For example, 
members **title** and **author** are dynamically allocated strings.

The exercise consists of two subtasks, each worth of exercise points. 
It is recommended that you implement the subtasks in order, because tests of later 
subtasks depend on the earlier implemented functions. You can also test and submit
the exercise after each subtask, to make testing easier, and to gain part of the 
points.

(a) Initialize book record
------------------

Implement function '**init_book**' that initializes a struct book instance pointed 
by parameter '**p_book**'. The structure does not need to be allocated in this function,
because the allocation is done elsewhere. However, you need to allocate needed memory
for those structure fields that need to be allocated separately.

The function returns 1, if initialization was successful, and 0 if it did not succeed. 
Initialization fails if function is called with invalid book ID. Invalid book ID
has more than 9 characters. You can assume that any other other book ID with 9 
characters or less is valid.

(b) Add new record
-----------------

Implement function '**add_to_collection**' that adds a new struct book record to the dynamic
array, and reallocates the array as needed. The start of the dynamic array is given
in parameter '**collection**', and the current length of the array is given in parameter
'**size**'. The new information to be added is given as parameter '**new_book**'. 
Note that the content of new_book needs to be copied to the array. Pay attention to
which parameters are pointers and which are not.

The function returns address to the dynamic array after the addition. This may be
same or different than the pointer given in '**collection**' parameter.
