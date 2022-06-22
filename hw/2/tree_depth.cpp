#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

Node* CreateNode(int data);
Node* InsertNode(Node* root, int data);
void preorder(Node *root);
int tree_depth(Node *root, int d);

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

void preorder(Node *root){
    if(root == NULL){
        return;
    }
    
	cout << root->data << ' ';
    preorder(root->left);
	preorder(root->right);
}

int tree_depth(Node *root, int d=0){
    if(root == NULL){
        return d-1;
    }
	return max(tree_depth(root->left, d+1), tree_depth(root->right, d+1));
}

int main(){
	Node* root = CreateNode(10);
	root->left = CreateNode(11);
	root->left->left = CreateNode(7);
	root->right = CreateNode(9);
	root->right->left = CreateNode(15);
	root->right->right = CreateNode(8);

	cout << "preorder traversal before insertion: ";
    
	preorder(root);
	cout << endl;

	int key = 12;
	root = InsertNode(root, key);

	cout << "preorder traversal after insertion: ";
    
	preorder(root);
	cout << endl;

    cout << tree_depth(root);
	return 0;
}
