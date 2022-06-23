#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char val;
    struct node *left, *right;
} NODE;

NODE* create_node(char val);
void insert_BST(NODE **node, char val);
void print_inorder(NODE *node);
void print_preorder(NODE *node);
void print_postorder(NODE *node);
int check_mirror(NODE *root1, NODE *root2);

NODE* create_node(char val){
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->val=val;
    node->left=node->right=NULL;
    return node;
}

void insert_BST(NODE **node, char val){
    if(*node == NULL){
        *node = create_node(val);
        return;
    }
    if((*node)->val >= val){
        insert_BST(&((*node)->left), val);
    }
    else{
        insert_BST(&((*node)->right), val);
    }
}

void print_inorder(NODE *node){
    if(node == NULL){
        return;
    }
    print_inorder(node->left);
    printf("%c ", node->val);
    print_inorder(node->right);
}

void print_preorder(NODE *node){
    if(node == NULL){
        return;
    }
    printf("%c ", node->val);
    print_preorder(node->left);
    print_preorder(node->right);
}

void print_postorder(NODE *node){
    if(node == NULL){
        return;
    }
    print_postorder(node->left);
    print_postorder(node->right);
    printf("%c ", node->val);
}

int check_mirror(NODE *root1, NODE *root2){
    if(root1 == NULL && root2 == NULL){
        return 1;
    }
    else if(root1 == NULL || root2 == NULL){
        return 0;
    }
    
    if(root1->val != root2->val){
        return 0;
    }
    return check_mirror(root1->left, root2->right) && check_mirror(root1->right, root2->left);
}

int main(){
    // a
    NODE *root = NULL;
    
    insert_BST(&root, 'd');
    insert_BST(&root, 'b');
    insert_BST(&root, 'c');
    insert_BST(&root, 'a');
    
    // b
    print_inorder(root);
    printf("\n\n");
    
    // c
    NODE *root1 = NULL;
    NODE *root2 = NULL;
    
    root1=create_node('d');
    root1->left=create_node('b');
    root1->right=create_node('c');
    root1->left->left=create_node('a');
    
    root2=create_node('d');
    root2->right=create_node('b');
    root2->left=create_node('c');
    root2->right->right=create_node('a');
    
    if(check_mirror(root1, root2)){
        printf("Trees are mirror of each other!\n");
    }
    else{
        printf("Trees are not mirror of each other!\n");
    }
    
    return 0;
}