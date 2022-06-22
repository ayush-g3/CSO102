#include <bits/stdc++.h>
using namespace std;

class BST{
    public:
        char val;
        BST *left, *right;
        
        BST(char v){
            val=v;
            left=right=NULL;
        }
};

void insert(BST *& root, char v){
    if(root == NULL){
        root = new BST(v);
        return;
    }
    if((root)->val >= v){
        insert(root->left, v);
    }
    else{
        insert(root->right, v);
    }
}

void print_inorder(BST *root){
    if(root == NULL){
        return;
    }
    print_inorder(root->left);
    cout << root->val << " ";
    print_inorder(root->right);
}

void print_preorder(BST *root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    print_inorder(root->left);
    print_inorder(root->right);
}

void print_postorder(BST *root){
    if(root == NULL){
        return;
    }
    print_inorder(root->left);
    print_inorder(root->right);
    cout << root->val << " ";
}

int main(){
    BST *root = NULL;
    
    insert(root, 'b');
    insert(root, 'a');
    insert(root, 'c');
    insert(root, 'd');
    
    print_inorder(root);
    return 0;
}