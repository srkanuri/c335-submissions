#include "stack.h"
/************************************************************************
 * main.c
 *
 * This is the program for the postfix calculator similar to the
 * dc implementation. It handles arithmetic operations like
 * +,-,*,/,~,& and | over numbers in a postfix notation.
 *
 * The program can be executed in the HW5 folder by running:
 * > make test
 *
 * We added a comprehensive test input in the file tests
 *
 * The main input are the numbers and operators +, -, *, /, &, | and ~.
 * NOTE: I have implemented ~ as the negation operator as opposed to -
 *       This is to differentiate between both operators in stack
 * Additional Commands:
 * p - peeks the first element in the stack
 * f - displays all the elements in the stack
 * c - clears/pops all the elements from the stack
 * q - quits the program
 *
 * Author: Srikanth Kanuri
 * Date Created: 11/16/2016
 * Last Modified by: Srikanth Kanuri
 * Date Last Modified: 11/16/2016
 * Assignment: HW5
 * Part of: HW5
 ***********************************************************************/
//Functions from push.s
extern void push(int);

//Functions from pop.s
extern int pop();

//Functions from operations.s
extern int or(int, int);
extern int and(int, int);
extern int plus(int, int);
extern int neg(int);
extern int minus(int, int);

//Functions from complex.c
extern void flush();
extern int prod(int, int);
extern int division(int, int);
extern int empty();
extern void peek();
extern void display();
extern void throw_error(int);

LIST top = NULL;

// Function Name: main
// Description: Processes the input and implements the postfix calculator
// Input: Command Line/File Input
// Return Value: returns 0
int main(){
  int inp;
  int val1,val2;
  int num=-1; //set the default value as -1
  while((inp = getchar()) != EOF){
    if(isdigit(inp)){
      if(num==-1){
        num=0;
      } //if the temp values is not initialised, set it to 0
      num=(10*num)+(inp-48); //Compute the number input by user and convert it from character to int
    } //check if the input is a digit (0 - 9)
    else{
      if(num!=-1){
        push(num);
        num=-1;
      } //check if the temp number variable is set. If set push it to stack and reset the temp variable.
      switch(inp){
      case '+': if(top != NULL && top->next != NULL){val1=pop(); val2=pop(); push(plus(val2,val1));} else {throw_error(1);} break;
      case '~': if(top != NULL){val1=pop(); push(neg(val1));} else {throw_error(1);} break;
      case '-': if(top != NULL && top->next != NULL){val1=pop(); val2=pop(); push(minus(val2,val1));} else {throw_error(1);} break;
      case '&': if(top != NULL && top->next != NULL){val1=pop(); val2=pop(); push(and(val2,val1));} else {throw_error(1);} break;
      case '|': if(top != NULL && top->next != NULL){val1=pop(); val2=pop(); push(or(val2,val1));} else {throw_error(1);} break;
      case '*': if(top != NULL && top->next != NULL){val1=pop(); val2=pop(); push(prod(val2,val1));} else {throw_error(1);} break;
      case '/': if(top != NULL && top->next != NULL){val1=pop(); val2=pop(); if(val1==0){throw_error(0);push(val2);push(val1);} else{push(division(val2,val1));}} else {throw_error(1);} break;
      case 'p': peek(); break;
      case 'f': display(); break;
      case 'q': exit(0);
      case 'c': flush(); break;
      case '\n': break;
      case '\t': break;
      case ' ': break;
      default : throw_error(2);
      } //switch case for additional operators
    } //if the input is not a digit
  }
  return 0;
}
