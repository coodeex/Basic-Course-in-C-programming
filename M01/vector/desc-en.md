**In this task, you will learn how to write a function that has a few parameters.
In addition, you will have to call some of the math library functions that are
present in a specific header files.**

Implement function titled **vectorlength(double x, double y, double z)** that calculates the length of the given 
three-dimensional euclidean vector. The function gets three arguments that represent 
the different components in the three-dimensional space. The function should return
the length of the vector. All numbers should be **double**-precision floating point 
numbers.

If you have forgotten about vector mathematics, you can find additional information
in the [Wikipedia]. You will need to calculate square root that is not part of C's 
basic operators, but there is a [sqrt] function in that math library that you can use. 
With [pow] function you can calculate power functions. See the detailed function 
specifications from the linked manual pages. To use sqrt, pow functions, include 
**math.h** header. Use **-lm** option in end of the compilation command to link 
math library like below:

    gcc -std=c99 -Wall -g -o main source.c -lm

Implement vector function in a file and write your own main function to 
test your function with various input vector values. When your function works properly, 
upload the program below and run your program.

[Wikipedia]: https://en.wikipedia.org/wiki/Vector_space
[sqrt]: http://linux.die.net/man/3/sqrt
[pow]: http://linux.die.net/man/3/pow
