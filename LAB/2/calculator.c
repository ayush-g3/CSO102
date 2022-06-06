#include <stdio.h>
#include "stack.h"
#include "infix_to_postfix.h"
#include "evaluate_postfix.h"

int main(){
    unsigned max_length = 30;
    char exp[max_length];
    
    strcpy(exp, "1+2+3*4");
    // scanf("%s",exp);
    
    char *postfix = infix_to_postfix(exp);
    // printf("%s\n", postfix);
    printf("%d" ,eval_postfix(postfix));
    return 0;
}