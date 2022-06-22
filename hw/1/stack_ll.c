#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
} node;

struct Stack{
    node *top;
};
typedef struct Stack Stack;

Stack* createStack(unsigned capacity){
    Stack *stack=(Stack *)malloc(sizeof(Stack));
    stack->top=NULL;
    return stack;
}

int isEmpty(Stack *stack){
    return stack->top == NULL;
}

int push(Stack *stack, int val){
    node *t = (node *)malloc(sizeof(node));
    t->val=val;
    t->next=stack->top;
    stack->top=t;
    return 1;
}

int pop(Stack *stack){
    if(isEmpty(stack)) return 0;
    node *t = stack->top;
    stack->top=t->next;
    int val = t->val;
    free(t);
    return val;
}

int peek(Stack *stack){
    if(isEmpty(stack)) return 0;
    return stack->top->val;
}

int main(){
    Stack *stack=createStack(10);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    printf("%d ", pop(stack));
    printf("%d ", peek(stack));
    push(stack, 9);
    printf("%d ", pop(stack));
    return 0;
}