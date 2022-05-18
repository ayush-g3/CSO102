#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    unsigned capacity;
    int *arr;
};

typedef struct Stack Stack;

Stack* createStack(unsigned capacity){
    Stack *stack=(Stack *)malloc(sizeof(Stack));
    stack->top=-1;
    stack->capacity=capacity;
    stack->arr=(int *)malloc(sizeof(int) * capacity);
    return stack;
}

int isEmpty(Stack *stack){
    return stack->top == -1;
}

int isFull(Stack *stack){
    return stack->top == stack->capacity-1;
}

int push(Stack *stack, int val){
    if(isFull(stack)) return 0;
    (stack->arr)[++(stack->top)]=val;
    return 1;
}

int pop(Stack *stack){
    if(isEmpty(stack)) return 0;
    return (stack->arr)[(stack->top)--];
}

int peek(Stack *stack){
    if(isEmpty(stack)) return 0;
    return (stack->arr)[(stack->top)];
}

int main(){
    Stack *stack=createStack(10);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    printf("%d", pop(stack));
    return 0;
}