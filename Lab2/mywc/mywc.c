#include <stdio.h>
/***************************************************************
 * mywc.c
 *
 * Counts the alphabets, words and lines in the given input
 *
 * Authors: Srikanth Kanuri (srkanuri)
 * Date Created: 09/02/2016
 * Last Modified by: Srikanth Kanuri
 * Date Last Modified: 09/08/2016
 * Assignment: Lab2
 * Part of: mywc
 ***************************************************************/

// Function Name: main
// Description: Function to count the words, lines and alphabets
// Return type: int
int main()
{
  int c;
  int wordcnt=0, linecnt=0, alphacnt=0;
  while((c=getchar()) != EOF){
    alphacnt++;
    if(c==32){
      wordcnt++;
    }
    if(c==10){
      linecnt++;
      wordcnt++;
    }
  }
  printf(" %d %d %d\n",linecnt,wordcnt,alphacnt);
}
