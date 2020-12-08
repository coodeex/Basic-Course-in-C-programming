### Programming task 2.5: Draw triangle (20 pts)

**In this task, students learn how to implement nested loops to produce below mentioned
triangle prints.**

Implement function **void draw_triangle(unsigned int size)** that draws an ASCII box 
that contains a triangle.

The box should be **size** characters wide, and **size** characters tall. The box is split
diagonally in two such that the righthand and bottom characters are `'#'`, and the 
lefthand and top characters are `'.'`.

The first line contains one `'#'` character at the right edge, the second line contains
two `'##'` characters, and so on. On the last line all characters are `'#'`.

All lines (also the last) end with a newline character `('\n')`.

Here is an example calling draw_triangle(5):
    
....#
...##
..###
.####
#####

To test **draw_triangle(unsigned int size)** function, for example, you should write 
a main function that asks user for an input unsigned integer (`%u`),
and calls **draw_triangle** function using the given input, and repeat this
loop until the program is interrupted (using command line  Ctrl + C
key combination).
