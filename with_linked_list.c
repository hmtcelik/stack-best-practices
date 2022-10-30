#include<stdio.h>
#include<stdlib.h>

/* defining stack capacity */
#define STACK_SIZE 3

/* defining structure of the linked list node */
struct node{
  int data;
  struct node *next;
};
typedef struct node Node;

/* defining structure of the stack */ 
typedef struct {
    int count;
    Node *top;
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
  stk->count = 0;
  stk->top = NULL;
}

/* inserting an element into the stack */
void push(Stack *stk, int value){
  if(stk->count == STACK_SIZE){
    printf("the stack is full\n");
    return;
  }
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = value;
  temp->next = stk->top;
  stk->top = temp;
  stk->count++;
}

/*
  getting top element of the stack
  and removing this top element
*/
int pop(Stack *stk){
  if(stk->count == 0){
    printf("the stack is empty\n");
    return -999; // dummy data
  }
  int x = stk->top->data;
  Node *temp = stk->top;
  stk->top = stk->top->next;
  stk->count--;
  free(temp);
  return x;
}