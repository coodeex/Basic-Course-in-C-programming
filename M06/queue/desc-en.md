### Programming task 6.5: Exercise queue (25 pts)

In this task you will implement a queueing system using a linked
list. The queue holds names (i.e., strings) of the members in the
queue. The length of the strings is not limited. The items in linked
list are stored in following data structures:

    struct studentqueue {
        char *name;  // Name of student (dynamically allocated)
        struct studentqueue *next;  // pointer to next student
	};

As mentioned above, the names of queue members can be arbitrarily
long, so the name should be stored in dynamically allocated
memory. To ease the handling of the list, the the first element is
always empty, and should be passed. In the first element, the *name*
field should always be NULL pointer. In the last element of the list,
the *next* pointer should be NULL. When the list is empty, both fields
are NULL in the first element. Below is a picture the illustrates a
queue with two members.

<img src="/staticfiles/ELEC-A7100/tasks/M6-stringqueue/M06-stringqueue.svg" width="60%">

You will need to implement two functions, both of which grant part of
the points in this task:

**(a):** Function `int enqueue(struct studentqueue *q, const char
*name)` that adds given *name* as the last item of the list (that
has NULL name in the beginning). The function makes two memory
allocations: one for the data structure, and other for the name. The
function returns value 1, if addition was succesful, and value 0 if
it failed (for example because of failed memory allocation).

**(b):** Function `int dequeue(struct studentqueue *q, char *buffer,
unsigned int size)` that removes the first item from the queue. Before
removing the item, the name it contains should be copied to address
*buffer*. In this address there is space for *size* characters, so you
can copy at most *size-1* characters. You should also release the
memory allocated for this item. The function returns value 1, if there
was an item removed from the list, and the related name is copied to
*buffer*. The function returns 0, if there was nothing removed from
the list, for example because the list was already empty.

In the implementation and testing, you should pay attention to the
special cases, such as the case of an empty list.
