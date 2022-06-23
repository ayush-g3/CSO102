#include <bits/stdc++.h>
using namespace std;

class NODE{
    public:
        char val;
        NODE *left, *right;
        
        NODE(char v){
            val=v;
            left=right=NULL;
        }
};

void insert_BST(NODE *& root, char v){
    if(root == NULL){
        root = new NODE(v);
        return;
    }
    if((root)->val >= v){
        insert_BST(root->left, v);
    }
    else{
        insert_BST(root->right, v);
    }
}

void print_inorder(NODE *root){
    if(root == NULL){
        return;
    }
    print_inorder(root->left);
    cout << root->val << " ";
    print_inorder(root->right);
}

void print_preorder(NODE *root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    print_inorder(root->left);
    print_inorder(root->right);
}

void print_postorder(NODE *root){
    if(root == NULL){
        return;
    }
    print_inorder(root->left);
    print_inorder(root->right);
    cout << root->val << " ";
}

int main(){
    NODE *root = NULL;
    
    insert_BST(root, 'b');
    insert_BST(root, 'a');
    insert_BST(root, 'c');
    insert_BST(root, 'd');
    
    print_inorder(root);
    return 0;
}