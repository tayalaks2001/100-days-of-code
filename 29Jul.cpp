// Question - Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even levels should be printed from right to left.

// sample input - 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

// level-wise tree structure - 
//        10
//    20      30
// 40   50  60  73

// sample output - 10 30 20 40 50 60 73 


#include<bits/stdc++.h>
using namespace std;

class node {
	public:
	int data;
	node *left, *right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

// construction from preorder style input
node* constructTree(){
	int d;
	cin>>d;
	node* root = new node(d);
	string l,r;
	cin>>l;
	if (l == "true"){
		root->left = constructTree();
	}
	cin>>r;
	if (r == "true"){
		root->right = constructTree();
	}
	
	return root;
}

void printLevelwise(node* root){
	queue<pair<node*, int>> traversal;
	traversal.push({root,0});
	int currLevel = 0;
	while (!traversal.empty()){
		node* curr = traversal.front().first;
		int l = traversal.front().second;
		if (l > currLevel){
			cout<<endl;
			currLevel++;
		}
		if (curr != NULL){
			cout<<curr->data<<" ";
			traversal.push({curr->left, l+1});
			traversal.push({curr->right, l+1});
		}
		traversal.pop();
	}
}

void printZigzag(node* root){
	stack<node*> toPrint;
	toPrint.push(root);

	int l = 0;
	while (!toPrint.empty()){
		stack<node*> next;
		while(!toPrint.empty()){
			node* curr = toPrint.top();
			toPrint.pop();
			if (curr != NULL){
				cout<<curr->data<<" ";
				if (l&1){
					next.push(curr->right);
					next.push(curr->left);
				}
				else{
					next.push(curr->left);
					next.push(curr->right);
				}
			}
		}
		l++;
		toPrint = next;
	}
	cout<<endl;
}

int main() {
	node* root = constructTree();
	printZigzag(root);
	return 0;
}
