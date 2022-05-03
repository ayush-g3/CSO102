#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

void create(struct node **, int);
void display(struct node *);
void reverse(struct node **);

void create(struct node **head, int val){
    if(*head==NULL){
        (*head)=(struct node *)malloc(sizeof(struct node));
        (*head)->val=val;
        (*head)->next=NULL;
    }
    else{
        struct node *p=(*head);
        while(p->next != NULL) p=p->next;
        p->next=(struct node *)malloc(sizeof(struct node));
        p=p->next;
        p->val=val;
        p->next=NULL;
    }
}
void display(struct node *head){
    while(head != NULL){
        printf("%d ", head->val);
        head=head->next;
    }
    printf("\n");
}

void reverse(struct node **head){
    struct node *prv, *p, *nxt;
    prv = (*head);
    p = (*head)->next;
    if(p != NULL){
        if(p->next == NULL){
            p->next=prv;
            prv->next=NULL;
            (*head)=p;
        }
        else{
            nxt=p;
            while(p != NULL){
                nxt=nxt->next;
                p->next=prv;
                prv=p;
                p=nxt;
            }
            (*head)->next=NULL;
            (*head) = prv;
        }
    }
}

int main(){
    struct node *head=NULL;
    
    create(&head, 1);
    create(&head, 2);
    create(&head, 3);
    create(&head, 4);
    display(head);
    reverse(&head);
    display(head);
    
    free(head);
    head=NULL;
}