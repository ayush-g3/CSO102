#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

#include <string.h>
#include "stack.h"

int isOperand(char t);
int precedence(char op);
int compare(char o1, char o2);
char* infix_to_postfix(char *exp);

int isOperand(char t){
    if((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z') || (t >= '0' && t <= '9'))
        return 1;
    return 0;
}

int precedence(char op){
    switch(op){
        case '^':
            return 3;
        case '%':
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int compare(char o1, char o2){
    return precedence(o1)-precedence(o2);
    // + then o1 > o2
    // - then o1 < o2
    // 0 then both equal prec...
}

char* infix_to_postfix(char *exp){
    unsigned exp_length = strlen(exp);
    struct Stack *stack = createStack(exp_length);
    int len = strlen(exp);
    char *res = (char *)malloc(sizeof(char) * 2 * (exp_length+1));
    int j=0;
    for(int i=0; i <= len; i++){
        char t = exp[i];
        if(isOperand(t)){
            int k=i;
            while(isOperand(t)){
                res[j++] = t;
                t = exp[++k];
            }
            res[j++] = ' ';
            i=k-1;
        }
        else if(t == '('){
            push(stack, t);
        }
        else if(t == ')'){
            char tmp = pop(stack);
            while(tmp != '('){
                res[j++] = tmp;
                res[j++] = ' ';
                tmp = pop(stack);
            }
        }
        else if(t != '\0' && t != ' '){
            repeat:
            if(isEmpty(stack) || peek(stack) == '('){
                push(stack, t);
            }
            else{
                int c = compare(t, peek(stack));
                if(c == 0){
                    if(t == '^'){
                        push(stack, t);
                    }
                    else{
                        res[j++]=pop(stack);
                        res[j++]=' ';
                        push(stack, t);
                    }
                }
                else if(c > 0){
                    push(stack, t);
                }
                else{
                    res[j++]=pop(stack);
                    res[j++]=' ';
                    goto repeat;
                }
            }
        }
        else if(t != ' '){
            char tmp = pop(stack);
            while(tmp != 0){
                res[j++]=tmp;
                res[j++]=' ';
                tmp=pop(stack);
            }
            res[j-1]='\0';
        }
    }
    deleteStack(stack);
    return res;
}

#endif