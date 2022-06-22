#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int val;
    struct element *next, *prev;
} ELEMENT;

typedef struct deque{
    ELEMENT *left, *right;
} DEQUE;

ELEMENT *create_element(int val){
    ELEMENT *elem=(ELEMENT *)malloc(sizeof(ELEMENT));
    elem->val=val;
    elem->next=elem->prev=NULL;
    return elem;
}

DEQUE* create_deque(){
    DEQUE *deque = (DEQUE *)malloc(sizeof(DEQUE));
    deque->left=deque->right=NULL;
    return deque;
}

int is_empty(DEQUE *deque){
    return deque->left==NULL && deque->right==NULL;
}

void push_left(DEQUE *deque, int val){
    ELEMENT *elem=create_element(val);
    if(is_empty(deque)){
        deque->left=deque->right=elem;
    }
    else{
        elem->next=deque->left;
        deque->left->prev=elem;
        deque->left=elem;
    }
}
void push_right(DEQUE *deque, int val){
    ELEMENT *elem=create_element(val);
    if(is_empty(deque)){
        deque->left=deque->right=elem;
    }
    else{
        deque->right->next=elem;
        elem->prev=deque->right;
        deque->right=elem;
    }
}

int pop_left(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    ELEMENT *elem=deque->left;
    deque->left=elem->next;
    int val=elem->val;
    free(elem);
    deque->left->prev=NULL;
    return val;
}
int pop_right(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    ELEMENT *elem=deque->right;
    deque->right=elem->prev;
    int val=elem->val;
    free(elem);
    deque->right->next=NULL;
    return val;
}

int peek_left(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    return deque->left->val;
}
int peek_right(DEQUE *deque){
    if(is_empty(deque)){
        printf("Deque is empty!!!\n");
        return INT_MIN;
    }
    return deque->right->val;
}

int main(){
    DEQUE *deque=NULL;
    deque=create_deque();
    
    push_left(deque, 3);
    push_right(deque, 1);
    push_right(deque, 2);
    push_left(deque, 9);
    printf("%d ", peek_right(deque));
    printf("%d ", pop_left(deque));
    printf("%d ", peek_left(deque));
    return 0;
}