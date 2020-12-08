### Programming task 9.1: Hex file (20 pts)

Implement function `int file_to_hex(const char *filename)` which reads from the file 
(file name is given as a parameter) and prints all contents of the file in hex format:
each of the file byte is printed in two-character hexadecimal format. If hex value 
is less than 0x10, then 0 must be appended to the front. Each line must have only 
16 hex values with space between hex values. Only 16 hex values must be printed in 
one line and there should be a space after the last value. After printing 16 hex values, move on to the next line. 

Here is an example output:

<pre>
0e 54 65 65 6d 75 20 54 65 65 6b 6b 61 72 69 30 
30 30 30 30 41 00 00 14 45 4c 45 43 2d 41 31 31 
30 30 00 00 00 00 00 00 00 </pre>

Function **file_to_hex** must return number of bytes read from the file or "-1" if an 
error occurs during reading from the file.
