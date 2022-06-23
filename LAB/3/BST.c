#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    char val;
    struct BST *left, *right;
} BST;

BST* create_node(char val);
void insert(BST **node, char val);
void print_inorder(BST *node);
void print_preorder(BST *node);
void print_postorder(BST *node);
int check_mirror(BST *root1, BST *root2);

BST* create_node(char val){
    BST *node = (BST *)malloc(sizeof(BST));
    node->val=val;
    node->left=node->right=NULL;
    return node;
}

void insert(BST **node, char val){
    if(*node == NULL){
        *node = create_node(val);
        return;
    }
    if((*node)->val >= val){
        insert(&((*node)->left), val);
    }
    else{
        insert(&((*node)->right), val);
    }
}

void print_inorder(BST *node){
    if(node == NULL){
        return;
    }
    print_inorder(node->left);
    printf("%c ", node->val);
    print_inorder(node->right);
}

void print_preorder(BST *node){
    if(node == NULL){
        return;
    }
    printf("%c ", node->val);
    print_inorder(node->left);
    print_inorder(node->right);
}

void print_postorder(BST *node){
    if(node == NULL){
        return;
    }
    print_inorder(node->left);
    print_inorder(node->right);
    printf("%c ", node->val);
}

int check_mirror(BST *root1, BST *root2){
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
    BST *root = NULL;
    
    insert(&root, 'd');
    insert(&root, 'b');
    insert(&root, 'c');
    insert(&root, 'a');
    
    // b
    print_inorder(root);
    printf("\n\n");
    
    // c
    BST *root1 = NULL;
    BST *root2 = NULL;
    
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