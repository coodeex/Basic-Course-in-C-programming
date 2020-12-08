### Programming task 2.3: Calculator (40 pts)

**In this task, you will learn to use conditional statements and formatted input 
  and output using scanf and printf. Two separate functions must be implemented in 
  this task, both of which will be reviewed and scored separately. Both of these 
  functions must be implemented in source.c - file. **
  
**simple_multiply**: Implement a function *simple_multiply* which asks user for 
two integers, multiplies both integers and finally, prints the result in the following 
format:

`1 * 2 = 2`

('`\n`') must be present at the end of input values and output value. 
In the following example,
user input (first line) and
output of the program with given input values (second line)

4 5
4 * 5 = 20
  
**simple_math**: Write function `void simple_math(void)` that asks three values from 
the user: number, operator, and another number. Operator should be one of the following 
characters: '+', '-', '*' or '/'. If some other character is used as operator, the 
function should print "ERR" (without quotes). The numbers should be **float** type. 
If user does not type a valid number-operator-number combination, the function 
should print "ERR". When valid input is given, the function performs the calculation
as given, and prints the result on the screen, using the **precision of one decimal**:

The following example shows sample input and output of the program:

8 - 2  (user input)
6.0  (answer)

5 * 5  (user input)
25.0  (answer)

8.3 / 5.1  (user input)
1.6  (answer)

-3.456 - 2.31  (user input)
-5.8  (answer)

As in the past, after implementing two functions , call it from the main funtion
and test the functions with various inputs.

**Hint**

  * Since **scanf** considers space as a delimiter for input, each input value must
    be given in separate lines or on the same line separated by spaces.
    
  * Check how to scan character constants using **scanf** function and also how to
    use character constants.
