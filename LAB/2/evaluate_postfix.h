#ifndef EVALUATE_POSTFIX_H
#define EVALUATE_POSTFIX_H

#include <math.h>
#include "stack.h"

int eval(int a, char op, int b);
int eval_postfix(char *postfix);

int eval(int a, char op, int b){
    switch (op){
    case '^':
        return pow(a,b);
    case '%':
        return a%b;
    case '/':
        return a/b;
    case '*':
        return a*b;
    case '+':
        return a+b;
    case '-':
        return a-b;
    default:
        return 0;
    }
}

int eval_postfix(char *postfix){
    int len=strlen(postfix);
    struct Stack *stack=createStack(len);
    for(int i=0; i < len; i++){
        char t=postfix[i];
        if(isOperand(t)){
            int tmp=0;
            while(t != ' '){
                tmp=tmp*10+(t-'0');
                t=postfix[++i];
            }
            push(stack, tmp);
        }
        else if(t != ' '){
            int b=pop(stack);
            int a=pop(stack);
            push(stack, eval(a, t, b));
        }
    }
    int ans=peek(stack);
    deleteStack(stack);
    return ans;
}

#endif