#include <stdio.h>
/***************************************************************
 * poly.c
 *
 * This program is used to fillup memory. It uses a union type
 * and loads the values. poly.c loads the values and dump.c
 * prints out the values. dump_memory is an external function
 * from dump.c which is also used in poly.c
 *
 * Authors: Srikanth Kanuri (srkanuri)
 *          Samuel Eleftheri (selefthe)
 * Date Created: 09/02/2016
 * Last Modified by: Srikanth Kanuri
 * Date Last Modified: 09/08/2016
 * Assignment: Lab2
 * Part of: poly
 ***************************************************************/

// Function Name: dump_memory
//
// Description: The dump_memory function is used to print out all the values
// loaded in poly.c. We first print out the header and then follow it with a 
// for loop which prints all the values. We are printing the 
// address, character, hex, short, int, float and double float
// 
// Input Parameters: Pointer to Union, Lenght of the Union type.
// Return: Void 
void dump_memory(void *p, int len)
{
  int i;
  printf("%-14s  %4s %5s %-6s %+11s%+13s %+13s\n","address","char","hexCh","short","integer","float","doubleFloat");
  for (i = 0; i < len; i++) {
    char tmp = *(unsigned char *)(p + i);
    printf("%+14p %4c 0x%02x %+6hd %+11d %+13e %+13e\n", p + i, ((tmp>31 && tmp<128) ? tmp :'?'), *(unsigned char *)(p + i), *(unsigned short *)(p + i), *(unsigned int *)(p + i), *(float *)(p + i), *(double *)(p + i));
  }//There is an additional logic to charaters to print the values of only those characters in ASCII range i.e. (32 - 127)
   //The other values are control characters and might not print correctly. Hence we replace them with a '?'.
}
