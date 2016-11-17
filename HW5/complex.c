#include "stack.h"
/************************************************************************
 * complex.c - Contains all complex functions in the calculator
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
extern LIST top;

int prod(int val1, int val2){
  return val1*val2;
}

int division(int val1, int val2){
  return val1/val2;
}

// Function Name: empty
// Description: Returns 1 if the stack is empty else returns 0
// Input: None
// Return Value: int
int empty(){
  if(top == NULL)
    return 1;
  else
    return 0;
}

// Function Name: throw_error
// Description: displays error based on the error code
// Input: The integer value of the error code
// Return Value: Void
void throw_error(int code){
  switch(code){
  case 0: printf("calc: divide by zero\n"); break;
  case 1: printf("calc: stack empty\n"); break;
  case 2: printf("calc: unimplemented operator\n"); break;
  default: printf("calc: You must be having a very bad time if you see this!\n");
  }
}

// Function Name: flush
// Description: Pops all the values from the stack
// Input: None
// Return Value: Void
void flush(){
  while(top!=NULL){
    pop();
  }
}

// Function Name: peek
// Description: Peeks into the stack to view the first element
// Input: None
// Return Value: Void
void peek(){
  if(top == NULL){
    throw_error(1);
    return;
  }
  printf("%d\n", top->val);
}

// Function Name: display
// Description: Displays all the elements in the stack
// Input: None
// Return Value: Void
void display(){
  LIST iter;
  for (iter=top; iter!=NULL; iter=iter->next){
    printf("%d\n", iter->val);
  }
}
