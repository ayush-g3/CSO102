#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct Stack{
    int top;
    unsigned capacity;
    int *arr;
};

// typedef struct Stack Stack;

/*
typedef struct Stack{
    int top;
    unsigned capacity;
    int *arr;
} Stack;
*/

struct Stack* createStack(unsigned capacity);
void deleteStack(struct Stack *stack);
int isEmpty(struct Stack *stack);
int isFull(struct Stack *stack);
int push(struct Stack *stack, int val);
int pop(struct Stack *stack);
int peek(struct Stack *stack);

struct Stack* createStack(unsigned capacity){
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (int *)malloc(sizeof(int) * capacity);
    return stack;
}

void deleteStack(struct Stack *stack){
    free(stack->arr);
    free(stack);
}

int isEmpty(struct Stack *stack){
    return stack->top == -1;
}
int isFull(struct Stack *stack){
    return stack->top == stack->capacity-1;
}
int push(struct Stack *stack, int val){
    if(isFull(stack)) return 0;
    (stack->arr)[++(stack->top)] = val;
    return 1;
}
int pop(struct Stack *stack){
    if(isEmpty(stack)) return 0;
    --(stack->top);
    return (stack->arr)[(stack->top)+1];
}
int peek(struct Stack *stack){
    if(isEmpty(stack)) return -1;
    return (stack->arr)[(stack->top)];
}

#endif
