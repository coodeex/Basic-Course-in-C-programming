### Programming task 9.4: Shop (25 pts)

In this task you should implement an imaginary shop's bookkeping system in two 
different ways. The products of the shop are given in a *Product* struct array. 
In one *product* element, there exists the product's name, price and the quantity 
of products in stock (see the header file for struct implementation). As said before, 
the accounting is done by an array of these *Product* elements. **The last element 
of the array has name of which first character is terminating null character (\\0).** 
You should implement four functions:

**(a)** function *output_binary* which outputs a binary format file from given 
Product array with parameter name *shop*. Another parameter for this function is 
*filename*, the name of the desired output file. If the function succeeded, it 
should return 0, otherwise it should return 1.

**(b)** function *read_binary*, which reads a binary format file (written in 
section a) and outputs the read data into a *Product*-array. After reading the 
data the function should return a pointer to this array. **The function must allocate 
the memory for this array** and the reading format should be so that the first 
array element read from the binary file should be in the first index of the list. 
Also remember to mark the last element of the list as described before. If the 
function does not succeed, it should return a *NULL* pointer.

**(c)** function *output_plaintext*, which outputs a plaintext format (ie. 
human readable) from the given *Product* array *shop*. The file format should be 
following:

    yoghurt 1.2 23
    muesli 4.3 12
As seen the data items of the struct are separated with a space, and the array 
elements are separated by a newline. Because the data items are separated by a 
space, the product name should not have spaces in it. Into this plaintext product 
file the last element (with the name of null character) should not be printed at 
all. As in the a-case, f the function succeeded, it should return 0, otherwise 
it should return 1.

**(d)** function *read_plaintext* which reads a plaintext file (written in 
section c) and outputs the read data into a *Product*-array. After reading the 
data the function should return a pointer to this array. **The function must allocate 
the memory for this array** and the reading format should be so that the first 
array element read from the binary file should be in the first index of the list. 
Also remember to mark the last element of the list as described in the very 
beginning of this task. If the function does not succeed, it should return a 
*NULL* pointer.


**Hints:**

* It may be easier to first implement the functions in parts c and d.
* When reading plaintext data, you should use the [sscanf](http://www.cplusplus.com/reference/cstdio/sscanf/) function.
* When dealing with binary files, use functions fread and fwrite. Use one fread/fwrite command for one *Product*.
* Do **not** write the last "null element" into the files. However, you have to remember to add the "null element" yourself to the end of an array.
* When dealing with plaintext files, do **not** add any format specifications, i.e. read a floating point with `%f`, not with `%0.1f`.

It is encouraged to make your own test files to test the function you are 
implementing. Implement your functions into the file *shop.c* based on the 
definitions from the *aaltoshop.h*-file.


**The files for this task:**

* **[main.c](/staticfiles/ELEC-A7100/tasks/M9-shop/main.c)** for testing

* **[aaltoshop.h](/staticfiles/ELEC-A7100/tasks/M9-shop/aaltoshop.h)** which has the needed 
definitions and declarations.
