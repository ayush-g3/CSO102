#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    char val;
    struct BST *left, *right;
} BST;

BST* create_node(char val){
    BST *node = (BST *)malloc(sizeof(BST));
    node->val=val;
    node->left=node->right=NULL;
    return node;
}

void insert(BST **root, char val){
    if(*root == NULL){
        *root = create_node(val);
        return;
    }
    if((*root)->val >= val){
        insert(&((*root)->left), val);
    }
    else{
        insert(&((*root)->right), val);
    }
}

void print_inorder(BST *root){
    if(root == NULL){
        return;
    }
    print_inorder(root->left);
    printf("%c ", root->val);
    print_inorder(root->right);
}

void print_preorder(BST *root){
    if(root == NULL){
        return;
    }
    printf("%c ", root->val);
    print_inorder(root->left);
    print_inorder(root->right);
}

void print_postorder(BST *root){
    if(root == NULL){
        return;
    }
    print_inorder(root->left);
    print_inorder(root->right);
    printf("%c ", root->val);
}

int main(){
    BST *root = NULL;
    
    insert(&root, 'b');
    insert(&root, 'a');
    insert(&root, 'c');
    insert(&root, 'd');
    
    print_inorder(root);
    return 0;
}