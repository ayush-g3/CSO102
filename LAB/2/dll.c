#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
    struct node * prev;
};

void create_head(struct node **, int);
void append(struct node *, int);
void display(struct node* );
void delete(struct node **, int);

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

void delete(struct node **head, int val){
    struct node *p=(*head);
    while(p!= NULL && p->val != val){
        p=p->next;
    }
    if(p == NULL){
        printf("Value to delete not found!!\n");
    }
    else{
        if(p == (*head)){
            p=p->next;
            free(p->prev);
            p->prev=NULL;
            (*head)=p;
        }
        else if(p->next == NULL){
            p=p->prev;
            free(p->next);
            p->next=NULL;
        }
        else{
            struct node *t = p->prev;
            p=p->next;
            free(p->prev);
            t->next=p;
            p->prev=t;
        }
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
    delete(&head, 2);
    display(head);
    
    free(head);
    return 0;
}