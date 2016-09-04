#include <stdio.h>
#include <stdlib.h>

typedef struct CELL *LIST;
 
struct CELL {
    int val;
    LIST next;
};

LIST top = NULL;

void push(int value){
  LIST elem = (LIST)malloc(sizeof(struct CELL));
  elem->val=value;
  elem->next=top;
  top=elem;
}

void pop(){
  if(top == NULL){
    printf("%s\n""Stack Empty");
    return;
  }
  int value = top->val;
  LIST temp = top;
  top = top->next;
  free(temp);
}

void peek(){
  if(top == NULL){
    return;
  }
  printf("%d\n", top->val);
  //printf("%d\n",top->next);
  //printf("%d\n",top);
}

void display(){
  LIST iter;
  for (iter=top; iter!=NULL; iter=iter->next){
    printf("%d\n", iter->val);
  }
}


int main(){
  int inp;
  int val1,val2;
  while((inp = getchar()) != EOF){
    int errflag = 0;
    //printf("Input: %d \t %c\n",inp, inp);
    switch(inp){
    case '+': if(top != NULL){val1 = top->val;} pop(); if(top != NULL){val2=top->val; errflag=1;} pop(); if(errflag==1){push(val1+val2);} break;
    case '-': if(top != NULL){val1 = top->val;} pop(); if(top != NULL){val2=top->val; errflag=1;} pop(); if(errflag==1){push(val1-val2);} break;
    case '*': if(top != NULL){val1 = top->val;} pop(); if(top != NULL){val2=top->val; errflag=1;} pop(); if(errflag==1){push(val1*val2);} break;
    case '/': if(top != NULL){val1 = top->val;} pop(); if(top != NULL){val2=top->val; errflag=1;} pop(); if(errflag==1){push(val1/val2);} break;
    case 'p': peek(); break;
    case 'f': display(); break;
    case 'q': exit(0);
    case '\n': break;
    case '\t': break;
    case ' ': break;
    default : push(inp-48);
    }
  }
}
