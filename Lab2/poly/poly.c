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
typedef union {
  unsigned char ccc[8];
  short sss[4];
  int iii[2];
  float fff[2];
  double ddd;
} Poly; //Union type of name Poly

extern void dump_memory(void *, int); //extenal function from dump.c used in the current file.

// Function Name: main
// Description: main function to start the program an load the memory using 
// the union structure. Once loaded, we use the dump_memory function
// to print out all the values.
// Return Type: int

 int main() {
   int i;
   Poly rawdata[6];
   
   for (i = 0; i < 8; i++) rawdata[0].ccc[i] = 'a' + i;
   for (i = 0; i < 8; i++) rawdata[1].ccc[i] = 42 + i;
   for (i = 0; i < 4; i++) rawdata[2].sss[i] = 5280 + i;
   for (i = 0; i < 2; i++) rawdata[3].iii[i] = 'A' + i;
   rawdata[4].fff[0] = 6.022e+23;
   rawdata[4].fff[1] = 2.9979245833e+8 ;
   rawdata[5].ddd = 3.14159265358979323846264;
   
   dump_memory(rawdata, sizeof(rawdata));

   return 0;
 }
