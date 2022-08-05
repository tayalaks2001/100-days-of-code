// Question - given an array input, build a balanced binary tree 

#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *l,*r;
    node(int d){
        data = d;
        l = r = NULL;
    }
};

node* buildBalancedTree(vector<int> ar, int start, int end){
    if (start > end)
        return NULL;

    int mid = (start+end)/2;
    node* root = new node(ar[mid]);
    root->l = buildBalancedTree(ar, start, mid-1);
    root->r = buildBalancedTree(ar, mid+1, end);

    return root;
}

int height(node* root){
    if (root == NULL)
        return 0;
    
    int h1 = height(root->l), h2 = height(root->r);
    return max(h1,h2) + 1;
}
