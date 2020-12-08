### Programming task 2.6: ASCII-table (20 pts)

***This task focuses on the [ASCII table](https://en.wikipedia.org/wiki/ASCII), helping to understand how the different
encoding works. At the same time become familiar with 
the various printf formats, as well as provide more practice on loops***

Implement function **void ascii_chart(char min, char max)** that outputs (a portion of) 
ASCII character mapping. It should iterate through numbers starting from *'min'* 
and ending to (and including) *'max'*.

  * three-character field that shows the given number as an integer. If the number
    takes less than three characters (it is < 100), it is aligned right.
  
  * one space, followed by four-character field that shows the same number in hexadecimal
    format. Each hexadecimal number should take two characters, and one-digit numbers
    are prefixed with 0. The whole hexadecimal number is prefixed with *'0x'*. 
    For example, number 1 is shown as *'0x01'*.
    
  * one space, followed by the same number when printed in character format (always
    one-character field). The number is converted into a character according to 
    ASCII coding system. 
  
    **Some character codes are not "printable"**, and do not produce sensible output 
    with this formatting. For non-printable characters, just '?' should be shown.
    You can use function `int isprint(int c)` ([man page][1]) to test if character in variable
    'c' is printable. If function returns 0, the character is not printable and 
    should show as '?'. If it is non-zero the character should be printed normally.
    
  * one tab `('\t')`, if the current line has less than four entries printed. On the
    fourth entry, you should change to the next line, i.e., instead of tab, print 
    newline `('\n')`.

[1]: http://linux.die.net/man/3/isprint "isprint manual page"

You should cycle through each number in the parameter range in the above-mentioned 
format (also including the max value). For example, call ascii_chart(28,38), should show the following:

28 0x1c ?	 29 0x1d ?	 30 0x1e ?	 31 0x1f ?
32 0x20  	 33 0x21 !	 34 0x22 "	 35 0x23 #
36 0x24 $	 37 0x25 %	 38 0x26 &
 