// Question - insertion into binary search tree

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

node* insertBST(node* root, int key){
    if (root == NULL)
        return new node(key);

    if (root->data >= key){
        root->left = insertBST(root->left, key);
    }
    else{
        root->right = insertBST(root->right, key);
    }

    return root;
}
