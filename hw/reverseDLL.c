#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
    struct node * prev;
};

void create_head(struct node **head, int val){
    if((*head) == NULL){
        (*head) = (struct node*)malloc(sizeof(struct node));
        (*head)->val=val;
        (*head)->next=NULL;
        (*head)->prev=NULL;
    }
    else{
        struct node*p=NULL;
        p = (struct node*)malloc(sizeof(struct node));
        p->val=val;
        p->next=(*head);
        p->prev=NULL;
        (*head)->prev=p;
        (*head)=p;
    }
}

void append(struct node *head, int val){
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=(struct node*)malloc(sizeof(struct node));
    p->next->prev=p;
    p=p->next;
    p->val=val;
    p->next=NULL;
}

void display(struct node* head){
    while(head!=NULL){
        printf("%d ", head->val);
        head=head->next;
    }
    printf("\n");
}

void insert_after(struct node *head, int fval, int ival){
    while(head->val != fval){
        head=head->next;
    }
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->val = ival;
    p->prev=head;
    p->next=head->next;
    head->next=p;
    if(p->next != NULL){
        p->next->prev=p;
    }
}

int delete_at(struct node **head, int pos){
    if(pos==0){
        (*head)=(*head)->next;
        free((*head)->prev);
        (*head)->prev=NULL;
        return 0;
    }
    struct node *p=(*head);
    while(--pos){
        p=p->next;
        if(p == NULL || p->next == NULL){
            printf("Delete Position wrong!!\n");
            return 0;
        }
    }
    struct node *temp=p->next;
    p->next=p->next->next;
    p->next->next->prev=p;
    free(temp);
}

void reverse(struct node **head){
    if((*head)->next != NULL){
        struct node *prv=NULL;
        struct node *p=(*head);
        struct node *nxt=p;
        while(p != NULL){
            nxt=nxt->next;
            p->next=prv;
            p->prev=nxt;
            prv=p;
            p=nxt;
        }
        (*head)=prv;
    }
}

int main(){
    struct node * head=NULL;
    
    //to create or update head use create_head function
    create_head(&head, 4);
    append(head, 3);
    append(head, 2);
    create_head(&head, 0);
    append(head, 5);
    display(head);
    
    insert_after(head, 5, 9);
    display(head);
    
    
    //note ll/dll are zero based
    delete_at(&head, 1);
    display(head);
    
    // reverse
    reverse(&head);
    display(head);
    
    free(head);
    return 0;
}