#include "bits.h"
#include <stdio.h>
#include <stdlib.h>

/* NOTE:
 * -----------
 * The parameter binary data (const unsigned char*) in all the functions 
 * below is likely to hold more than 8 bits. You should take this into 
 * account when implementing your functions.
 * 
 *Ei looppeja. Selvitä ensin mitä datan indeksiä 
 (monesko tavu) pitää muuttaa. Eli pitääkö muuttaa 
 jotakin bitti tavussa data[0] vai data[1] jne. Sitten
  selvitä monesko bitti tässä tavussa pitää muuttaa.
   Bitti muutetaan bittimaskilla 
   (Mieti millaista numeroa pitäisi käyttää maskina 
   että bitti menisi päälle. Mikä operaattori on kyseessä?).
 * 
 * Kiitos! Sekoitti, kun ohjeissa sanottiin,
 *  että tiettyä indeksiä ei löydä esim array[5],
 *  niin en hoksannut että kuitenkin piti käyttää
 *  nuita data[0], data[1] että löytää oikean tavun.
 *  Tällä lähti etenemään.
 * because data is a pointer, so the first byte is in data[0]
 * 
 DESCRIPTION:
 * ------------
 * The function sets a bit with index i as active (1) in the parameter
 * binary data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * unsigned char* data: an array of binary data.
 * int i: the index of the bit which to set as active (1).
 *
 * RETURNS:
 * ------------
 * Nothing.
 *
 */
void op_bit_set(unsigned char* data, int i)
{
  int i1 = i/8;
  int i2 = i1 * 8;
  int i3 = i - i2;
  data[i1] |= 1 << (7-i3);
}

/* DESCRIPTION:
 * ------------
 * The function sets a bit with index i as inactive (0) in the parameter
 * binary data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * unsigned char* data: an array of binary data.
 * int i: the index of the bit which to set as active (1).
 *
 * RETURNS:
 * ------------
 * Nothing.
 *
 */

void op_bit_unset(unsigned char* data, int i)
{
  int i1 = i/8;
  int i2 = i1 * 8;
  int i3 = i - i2;
  data[i1] &= ~(1 << (7-i3));
}

/* DESCRIPTION:
 * ------------
 * The functions returns 1 or 0 depending on whether the bit with index i in
 * the binary data is set or not.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * const unsigned char* data: an array of binary data.
 * int i: the index of the bit which value to return.
 *
 * RETURNS:
 * ------------
 * 0: if the bit was not set.
 * 1: if the bit was set.
 */

int op_bit_get(const unsigned char* data, int i)
{
  int i1 = i/8;
  int i2 = i1 * 8;
  int i3 = 7-(i - i2);
  if(data[i1] & (1<<i3)){
    return 1;
  }
  else{
    return 0;
  }
}

/* DESCRIPTION:
 * ------------
 * The function prints the binary representation of the parameter unsigned char
 * to the standard output as 1s and 0s. Note that one unsigned char is 8 bits.
 * There is no newline at the end of the print.
 *
 * For example:
 *
 * unsigned char b = 0xF8;
 * print_byte(b); 
 *
 * Would print out:
 *
 * 11111000
 *
 * PARAMETERS:
 * ------------
 * unsigned char b: the binary sequence.
 *
 * RETURNS:
 * ------------
 * Nothing.
 *
 */

void op_print_byte(unsigned char b)
{
  int i;
  for (i = 0; i < 8; i++) {
    printf("%d", !!((b << i) & 0x80));
  }
}

/* DESCRIPTION:
 * ------------
 * The function extracts a sequence of bits from the binary data. The length of 
 * the sequence is defined in by the parameter how_many and the sequence starts
 * from index i (inclusive).
 *
 * If the parameter how_many is less than 8, the byte will be padded with zeroes
 * on the left side. For example if you extract 2 bits (11), the return value
 * is 00000011, which is equal to 3.
 *
 * The maximum length of extracted sequence for this function is 8, you do not
 * need to handle any invalid parameters.
 *
 * NOTE: The const unsigned char* data is likely to hold more than one byte of
 *       information. The extracted sequence also can continue over byte
 *       boundaries i.e. the extracted bit data can exist within two different
 *       bytes.
 *
 * PARAMETERS:
 * ------------
 * const unsigned char* data: an array of binary data, where the sequence is 
 * extracted from.
 *
 * int i: the starting index of the extracted sequence.
 * int how_many: the length of the extracted sequence.
 *
 * RETURNS:
 * ------------
 * The extracted sequence stored in a single unsigned char.
 *
 */

unsigned char reverse(unsigned char b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
  }

unsigned char op_bit_get_sequence(const unsigned char* data, int i, int how_many)
{
  int x = 0;
  unsigned char c = 0;

  /*for(int a=0;a<8;a++){
    c &= ~(1 << a);
  }*/
  
  
    for(;x<how_many;x++) {
    //if(op_bit_get(data,i+x)){
      //c|=1<<(x);
      //c |= 1 << (x);
      //c |= (7-x) >> 1;
    //}else{
     // c|=0<<(x);
     c<<=1;
     c|= op_bit_get(data,i+x);
    
  }
  //reverse(c);

  return c;
}

void main() {
  int i1 = 20/8;
  int i2 = i1 * 8;
  int i3 = 20 - i2;
  printf("%d\n", i1);
  printf("%d\n", i2);
  printf("%d\n", i3);

}