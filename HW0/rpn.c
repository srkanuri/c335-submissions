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

void throw_error(int code){
  switch(code){
  case 1: printf("rpn: %s\n""stack empty");
  default: printf("rpn: %s\n""unknown error");
  }
}

void pop(){
  if(top == NULL){
    throw_error(1);
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
}

void display(){
  LIST iter;
  for (iter=top; iter!=NULL; iter=iter->next){
    printf("%d\n", iter->val);
  }
}

void flush(){
  while(top!=NULL){
    pop();
  }
}


int main(){
  int inp;
  int val1,val2;
  while((inp = getchar()) != EOF){
    switch(inp){
    case '+': if(top != NULL && top->next != NULL){val1 = top->val; pop(); val2=top->val; pop(); push(val1+val2);} else {throw_error(1);} break;
    case '-': if(top != NULL && top->next != NULL){val1 = top->val; pop(); val2=top->val; pop(); push(val1+val2);} else {throw_error(1);} break;
    case '*': if(top != NULL && top->next != NULL){val1 = top->val; pop(); val2=top->val; pop(); push(val1+val2);} else {throw_error(1);} break;
    case '/': if(top != NULL && top->next != NULL){val1 = top->val; pop(); val2=top->val; pop(); push(val1+val2);} else {throw_error(1);} break;
    case 'p': peek(); break;
    case 'f': display(); break;
    case 'q': exit(0);
    case 'c': flush(); break;
    case '\n': break;
    case '\t': break;
    case ' ': break;
    default : push(inp-48);
    }
  }
}
