### Programming task 6.3: Fraction (20 pts)

We practice abstract data types by implementing a new number type, 
[fraction](http://en.wikipedia.org/wiki/Fraction_(mathematics)), that 
consists of numerator and denominator. For example 2/3 and 4/6 are equivalent values, 
where 2 and 4 are numerators, and 3 and 6 are denominators. A new data type, Fraction 
is used to represent fractions. First you need to define the fraction_st struct
as needed in the **fraction.h** file. Functions need to be declared in the header
file (**fraction.h**) and defined in the source file (**fraction.c**).

Aluksi täytyy toteuttaa
kuvausta vastaava määrittely struct fraction_st:lle
**fraction.h**-tiedostoon. Funktiot pitää esitellä otsakkeessa (ladattavassa 
pakettissa ne on valmiina) ja toteuttaa lähdetiedostoon (**fraction.c**).

In this task, you will implement the functions listed below.

(a) Set value
---------------

Implement function `Fraction* setFraction(unsigned int numerator, unsigned int 
denominator)` that allocates a new Fraction from heap, sets its value as given in 
parameters, and returns the created object.

In addition, implement also the following simple functions:

  * `void freeFraction(Fraction* f)` that releases the memory used by the Fraction.

  * `unsigned int getNum(const Fraction *f)` that returns the numerator part of the fraction.

  * `unsigned int getDenom(const Fraction *f)` that returns the denominator part of the fraction.

(b) Compare values
--------------------

Implement function `int compFraction(const Fraction *a, const Fraction *b)` that 
returns -1 if a < b, 0 if a == b, or 1 if a > b. The function should work correctly 
also when denominators are different.
  
(c) Add values
----------------

Implement function `Fraction *addFraction(const Fraction *a, Fraction *b)` that adds
values 'a' and 'b', and returns the result in a new object allocated from heap. Again, 
the denominators may be different in the two numbers. The resulting value does not 
need to be reduced to smallest possible denominator.

**Hint:** Start by modifying the two numbers such that they have the same denominator.
  
(d) Reduce value
------------------

Implement function `void reduceFraction(Fraction *val)`, that reduces the value to 
the smallest possible denumerator. For example, using this function 3/6 should reduce
to 1/2. For doing this, you'll need to find the greatest common divisor for the 
numerator and denominator. The exercise template file **fraction.c** contains 
function `unsigned int gcd(unsigned int u, unsigned int v)` 
(source: [wikipedia](http://en.wikipedia.org/wiki/Binary_GCD_algorithm)), 
that you can use from your function.)
