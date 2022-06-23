#include <stdio.h>
#include <stdlib.h>

typedef struct deque{
    int front, rear;
    int capacity;
    int *arr;
} DEQUE;

DEQUE* create_deque(unsigned capacity);
int is_empty(DEQUE *deque);
int is_full(DEQUE *deque);
void push_front(DEQUE *deque, int val);
void push_rear(DEQUE *deque, int val);
int pop_front(DEQUE *deque);
int pop_rear(DEQUE *deque);
int peek_front(DEQUE *deque);
int peek_rear(DEQUE *deque);

DEQUE* create_deque(unsigned capacity){
    DEQUE *deque = (DEQUE *)malloc(sizeof(DEQUE));
    deque->front=-1;
    deque->rear=-1;
    deque->capacity=capacity;
    deque->arr=(int *)malloc(sizeof(int) * capacity);
    return deque;
}

int is_empty(DEQUE *deque){
    return deque->front == -1 && deque->rear == -1;
}

int is_full(DEQUE *deque){
    if(deque->rear == deque->front-1){
        return 1;
    }
    else if(deque->front == 0 && deque->rear == deque->capacity -1){
        return 1;
    }
    return 0;
}

void push_front(DEQUE *deque, int val){
    if(is_full(deque)){
        printf("Deque is full from left side!!!\n");
    }
    if(is_empty(deque)){
        deque->front=deque->rear=0;
    }
    else{
        --(deque->front) == -1 ? deque->front = deque->capacity-1 : 0;
    }
    deque->arr[deque->front]=val;
}
void push_rear(DEQUE *deque, int val){
    if(is_full(deque)){
        printf("Deque is full from right side!!!\n");
    }
    if(is_empty(deque)){
        deque->front=deque->rear=0;
    }
    else{
        ++(deque->rear) == deque->capacity ? deque->rear = 0 : 0;
    }
    deque->arr[deque->rear]=val;
}

int pop_front(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    int val=deque->arr[deque->front];
    if(deque->front == deque->rear){
        deque->front=deque->rear=-1;
    }
    else{
        ++(deque->front) == deque->capacity ? deque->front = 0 : 0;
    }
    return val;
}
int pop_rear(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    
    int val=deque->arr[deque->rear];
    if(deque->front == deque->rear){
        deque->front=deque->rear=-1;
    }
    else{
        --(deque->rear) == -1 ? deque->rear = deque->capacity-1 : 0;
    }
    return val;
}

int peek_front(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    return deque->arr[deque->front];
}
int peek_rear(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    return deque->arr[deque->rear];
}

int main(){
    DEQUE *deque=NULL;
    
    unsigned capacity=10;
    deque=create_deque(capacity);
    
    push_rear(deque, 3);
    push_front(deque, 1);
    push_front(deque, 2);
    push_rear(deque, 9);
    printf("%d ", peek_front(deque));
    printf("%d ", pop_rear(deque));
    printf("%d ", peek_rear(deque));
    return 0;
}