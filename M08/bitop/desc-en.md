### Programming task 8.4: Bit operations (30 pts)

**Objective**: In this task, you will learn how to do how to do some basic operations 
with bitfields and such.

The program deals with the array, which is consist of several bytes. Your task is 
to implement functions that manipulate individual bits in the array. Please read 
**Notes** below before starting implementation. 

Your task is to implement the following functions:

**a) Basic operations**

In the following functions, *data* parameter indicates start of the array and *i* 
parameter denotes position of the bit in the input array.

Implement the following functions which manipulates **bit** of input array:

* `void op_bit_set(unsigned char* data, int i)` -- sets a bit in input **data**.

* `void op_bit_unset(unsigned char* data, int i)` -- resets a bit in input **data**.

* `int op_bit_get(const unsigned char* data, int i)` -- returns value 0, if bit value 
   in **i** is zero and returns value 1, if bit value in **i** is one.

**b) Print a byte**

Implement function `void op_print_byte(unsigned char b)`, which prints one unsigned char's binary representation.

**c) Get a sequence**

Implement function `unsigned char op_bit_get_sequence(const unsigned char* data, int i, int how_many)`, that separates a maximum of 8 bits long binary number from the array 
and returns it. **i** and **data** have same meaning as above. **how_many** indicates
how many bits need to be counted from the i (max. 8). If how_many is less than 8, 
the most significant bits of the returned number is left with zeros. In this
task, you may want to take advantage of function implemented in (a).

**Notes:**

  * In this task, bit 0 is the most significant bit. It is also assumed that **unsigned 
    char** is exactly 8 bits (1 byte). Thus, for example, bit 8 is a leftmost bit in second 
    unsigned char byte and bit 17 is the second highest bit in the third unsigned 
    char byte. Thus, examining the number 170 (0xAA hexadecimal format, 10101010 
    in binary), the most significant bit, ie bit 0 has a value of 1.
  
  * If you find yourself implementing some sort of helper array of characters or 
    integers, then you are doing something wrong.
    
  * Bit 5 from an array is not array[5].
  
  * If given binary data is `1110 0101 1111 0011 0001 1110 0100 1111`, 
    and the `op_bit_get_sequence` function is called with index 20, and how_many of 5,
    return value should be 28, i.e. 5 first bits of the number `1110 0100 1111` 
    from the 20th index i.e. `1 1100`. The return value should then be `0001 1100` 
    ( ` 0001 1100 ` = 28).
