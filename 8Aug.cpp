// Question - build binary search tree from preorder traversal

#include <bits/stdc++.h>
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

node* buildBSTFromPre(vector<int> pre, int upper = INT_MAX, int &i){
    if (i > pre.size() or pre[i] > upper)
        return NULL;

    node* root = new node(pre[i++]);
    root->left = buildBSTFromPre(pre,root->data,i);
    root->right = buildBSTFromPre(pre,upper,i);

    return root;
}
