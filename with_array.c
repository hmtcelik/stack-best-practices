#include<stdio.h>
#include<stdlib.h>

/* defining stack capacity */
#define STACK_SIZE 3

/* defining structure of the stack */ 
typedef struct {
    int top;
    int data[STACK_SIZE];
}Stack;

/* prototypes of functions */ 
void init(Stack *stk);
void push(Stack *stk, int value);
int  pop(Stack *stk);

/* main function */
int main(){
  Stack stack;
  init(&stack);
  push(&stack, 2);
  int a = pop(&stack);
  printf("%d\n", a);
  return 0;
}

/* initializing the stack */
void init(Stack *stk){
  stk->top = -1;
}

/* inserting an element into the stack */
void push(Stack *stk, int value){
  if(stk->top == STACK_SIZE - 1 ){
    printf("the stack is full\n");
    return;
  }
  stk->data[++stk->top] = value;
}

/*
  getting top element of the stack
  and removing this top element
*/
int pop(Stack *stk){
  if(stk->top == -1){
    printf("the stack is empty\n");
    return -999; // dummy data
  }
  return stk->data[stk->top--];
}
