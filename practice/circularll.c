#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

void append(struct node **, int);
void display(struct node *);

void append(struct node **last, int val){
    if((*last) == NULL){
        (*last) = (struct node *)malloc(sizeof(struct node));
        (*last)->val=val;
        (*last)->next=(*last);
    }
    else{
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->val=val;
        p->next=(*last)->next;
        (*last)->next=p;
    }
}


// understand the usage difference between while and do-while
void display(struct node *last){
    struct node *p=last->next;
    do{
        printf("%d ", p->val);
        p=p->next;
    } while(p != last->next);
    printf("\n");
}

int main(){
    struct node *last = NULL;
    append(&last, 2);
    append(&last, 3);
    append(&last, 9);
    append(&last, 8);
    display(last);
    return 0;
}