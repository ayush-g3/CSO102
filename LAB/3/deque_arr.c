#include <stdio.h>
#include <stdlib.h>

typedef struct deque{
    int left, right;
    int size;
    int *arr;
} DEQUE;

DEQUE* create_deque(unsigned size){
    DEQUE *deque = (DEQUE *)malloc(sizeof(DEQUE));
    deque->left=size/2;
    deque->right=size/2+1;
    deque->size=size;
    deque->arr=(int *)malloc(sizeof(int) * size);
    return deque;
}

int is_empty(DEQUE *deque){
    return deque->left==deque->right-1;
}

int is_full(DEQUE *deque, int side){
    if(side == -1){
        return deque->left==-1;
    }
    else if(side == 1){
        return deque->right==deque->size;
    }
    return INT_MIN;
}

int push_left(DEQUE *deque, int val){
    if(is_full(deque, -1)){
        printf("Deque is full from left side!!!\n");
        return INT_MIN;
    }
    deque->arr[(deque->left)--]=val;
    return 0;
}
int push_right(DEQUE *deque, int val){
    if(is_full(deque, 1)){
        printf("Deque is full from right side!!!\n");
        return INT_MIN;
    }
    deque->arr[(deque->right)++]=val;
    return 0;
}

int pop_left(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    return deque->arr[++(deque->left)];
}
int pop_right(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    return deque->arr[--(deque->right)];
}

int peek_left(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    return deque->arr[(deque->left)+1];
}
int peek_right(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    return deque->arr[(deque->right)-1];
}

int main(){
    DEQUE *deque=NULL;
    
    unsigned size=10;
    deque=create_deque(size);
    
    push_left(deque, 3);
    push_right(deque, 1);
    push_right(deque, 2);
    push_left(deque, 9);
    printf("%d ", peek_right(deque));
    printf("%d ", pop_left(deque));
    printf("%d ", peek_left(deque));
    return 0;
}