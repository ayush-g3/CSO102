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

void append(struct node *head, int val){
    while(head->next != NULL){
        head=head->next;
    }
    head->next=(struct node *)malloc(sizeof(struct node));
    head=head->next;
    head->val=val;
    head->next=NULL;
}

void display(struct node *head){
    printf("DISPLAY: ");
    while(head != NULL){
        printf("%d ", head->val);
        head=head->next;
    }
    printf("\n");
}

void insert_after(struct node *head, int fval, int ival){
    while(head != NULL && head->val != fval){
        head=head->next;
    }
    if(head == NULL){
        printf("Given element %d not found!!\n",fval);
    }
    else{
        struct node *temp = head->next;
        head->next=(struct node *)malloc(sizeof(struct node));
        head=head->next;
        head->val=ival;
        head->next=temp;
    }
}

void delete(struct node**head, int val){
    if((*head)->val == val){
        struct node *temp = (*head)->next;
        free((*head));
        (*head)=temp;
    }
    else{
        struct node *p=*head;
        while(p->next != NULL && p->next->val != val){
            p=p->next;
        }
        if(p->next == NULL){
            printf("Element %d not found to be deleted!!\n", val);
        }
        else{
            struct node *temp = p->next->next;
            free(p->next);
            p->next=temp;
        }
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
    insert_after(head, 99, 9);
    insert_after(head, 0, 9);
    display(head);
    delete(&head,0);
    delete(&head, 99);
    display(head);
    
    free(head);
    head=NULL;
    return 0;
}