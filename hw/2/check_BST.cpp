#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

// function declarations
Node* CreateNode(int data);
Node* InsertNode(Node* root, int data);
int max_val_subtree(Node *root);
int isLeaf(Node *root);
int check_bst_node(Node *root);
int check_BST_preorder(Node *root);

Node* CreateNode(int data){
	Node* newNode = new Node;
    
	if (!newNode){
		cout << "Memory error\n";
		return NULL;
	}
    
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* InsertNode(Node* root, int data){
	if (root == NULL){
		root = CreateNode(data);
		return root;
	}

	queue <Node *> q;
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		else{
			temp->left = CreateNode(data);
			return root;
		}

		if (temp->right != NULL)
			q.push(temp->right);
		else{
			temp->right = CreateNode(data);
			return root;
		}
	}
    
    return NULL;
}

int max_val_subtree(Node *root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root->data, max(max_val_subtree(root->left), max_val_subtree(root->right)));
}

int isLeaf(Node *root){
	if(root->left == NULL && root->right == NULL)
		return 1;
	return 0;
}

int check_bst_node(Node *root){
	int a=max_val_subtree(root->left);
	int b=root->data;
	int c=max_val_subtree(root->right);
	if(isLeaf(root))
		return 1;
	else if((root->left == NULL && b<=c) || (root->right == NULL && a<=b) || (a<=b && b<=c))
		return 1;
	return 0;
}

int check_BST_preorder(Node *root){
    if(root == NULL){
        return 1;
    }
    if(check_bst_node(root) == 0){
        return 0;
    }
    return check_BST_preorder(root->left) && check_BST_preorder(root->right);
}

int main(){
	Node* root = CreateNode(20);
	root->left = CreateNode(11);
	root->left->left = CreateNode(7);
	root->right = CreateNode(21);
	root->right->left = CreateNode(19);
	root->right->right = CreateNode(23);

	int key = 12;
	root = InsertNode(root, key);
	
	if(check_BST_preorder(root)) cout << "BST" ;
	else cout << "Not BST" ;
	
	cout << "\n" ;
	return 0;
}