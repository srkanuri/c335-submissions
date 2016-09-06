#include <stdio.h>
#include <stdlib.h>
/*****************************************************************
 * rpn.c
 *
 * This is the program for the postfix calculator similar to the
 * dc implementation. It handles arithmetic operations like 
 * +,-,*,/ over numbers in a postfix notation.
 * 
 * The program can be executed in the HW0 folder by running:
 * > make rpn
 * > ./rpn
 *
 * The input can be provided in the command line or through a file.
 *
 * The main input are the numbers and operators +, -, *, /.
 * Additional Commands:
 * p - peeks the first element in the stack
 * f - displays all the elements in the stack
 * c - clears/pops all the elements from the stack
 * q - quits the program
 *
 * Author: Srikanth Kanuri
 * Date Created: 09/04/2016
 * Last Modified by: Srikanth Kanuri
 * Date Last Modified: 09/05/2015
 * Assignment: HW0
 * Part of: HW0
 ****************************************************************/

typedef struct CELL *LIST;
 
struct CELL {
    int val;
    LIST next;
};

LIST top = NULL;

// Function Name: push
// Description: Pushes a value into the stack
// Input: The integer value to be pushed into the stack
// Return Value: Void
void push(int value){
  LIST elem = (LIST)malloc(sizeof(struct CELL));
  elem->val=value;
  elem->next=top;
  top=elem;
}

// Function Name: throw_error
// Description: displays error based on the error code
// Input: The integer value of the error code
// Return Value: Void
void throw_error(int code){
  switch(code){
  case 0: printf("rpn: %s\n","divide by zero"); break;
  case 1: printf("rpn: %s\n","stack empty"); break;
  case 2: printf("rpn: %s\n","unimplemented operator"); break;
  default: printf("rpn: %s\n","You must be having a very bad time if you see this!");
  }
}

// Function Name: pop
// Description: Pops a value from the stack and deallocates the memory associated
// Input: None
// Return Value: The int value popped out
int pop(){
  if(top == NULL){
    throw_error(1);
    return;
  }
  int value = top->val;
  LIST temp = top;
  top = top->next;
  free(temp);
  return value;
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

// Function Name: flush
// Description: Pops all the values from the stack
// Input: None
// Return Value: Void
void flush(){
  while(top!=NULL){
    pop();
  }
}

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
      case '+': if(top != NULL && top->next != NULL){val1=pop(); val2=pop(); push(val2+val1);} else {throw_error(1);} break;
      case '-': if(top != NULL && top->next != NULL){val1=pop(); val2=pop(); push(val2-val1);} else {throw_error(1);} break;
      case '*': if(top != NULL && top->next != NULL){val1=pop(); val2=pop(); push(val2*val1);} else {throw_error(1);} break;
      case '/': if(top != NULL && top->next != NULL){val1=pop(); val2=pop(); if(val1==0){throw_error(0);push(val2);push(val1);} else{push(val2/val1);}} else {throw_error(1);} break;
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
