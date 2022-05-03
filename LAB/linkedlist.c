#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

void insert_begin(struct node **, int);
void append(struct node*, int);
void display(struct node *);
void insert_after(struct node*, int, int);
void delete(struct node**, int);

void insert_begin(struct node **head, int val){
    struct node*p = (struct node *)malloc(sizeof(struct node));
    p->val=val;
    if(*head==NULL){
        p->next=NULL;
    }
    else{
        p->next=*head;
    }
    *head=p;
}

void append(struct node*head, int val){
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=(struct node *)malloc(sizeof(struct node));
    p=p->next;
    p->val=val;
    p->next=NULL;
}

void display(struct node *head){
    struct node *p=head;
    printf("START\n");
    while(p != NULL){
        printf("%d ", p->val);
        p=p->next;
    }
    printf("\nEND\n");
}

void insert_after(struct node*head, int fval, int ival){
    struct node *p=head;
    while(p->val != fval){
        p=p->next;
    }
    struct node *temp = p->next;
    p->next=(struct node *)malloc(sizeof(struct node));
    p=p->next;
    p->val=ival;
    p->next=temp;
}

void delete(struct node**head, int val){
    if((*head)->val == val){
        struct node *temp = (*head)->next;
        free((*head));
        (*head)=temp;
    }
    else{
        struct node *p=*head;
        while(p->next->val != val){
            p=p->next;
        }
        struct node *temp = p->next->next;
        free(p->next);
        p->next=temp;
    }
}

int main(){
    struct node *head=NULL;
    // NOTE: to create/update head always use insert_begin function not append
    insert_begin(&head, 2);
    append(head, 3);
    append(head, 5);
    insert_begin(&head, 0);
    display(head);
    insert_after(head, 0, 9);
    display(head);
    delete(&head,0);
    display(head);
    
    free(head);
    head=NULL;
    return 0;
}