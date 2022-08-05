// Question - given preorder and inorder traversal arrays, construct the tree

#include<bits/stdc++.h>
using namespace std;

class node {
	public:
	int data;
	node *left, *right;

	node(int d){
		data = d;
		left = right = NULL;
	}
};

node* buildTree(vector<int> pre, vector<int> ino, int start, int end, int& i){
	if (start > end)
		return NULL;
	
	int data = pre[i];
	node* root = new node(data);
	int pos = find(ino.begin(), ino.end(), data) - ino.begin();
	i++;
	root->left = buildTree(pre,ino,start,pos-1,i);
	root->right = buildTree(pre,ino,pos+1,end,i);
	return root;
}
