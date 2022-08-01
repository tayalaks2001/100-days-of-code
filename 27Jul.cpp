// Question - level order traversal of binary tree

#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    node (int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* constructTreePreorder(){
    int d;
    cin>>d;
    if (d == -1)
        return NULL;
    
    node* root = new node(d);
    root->left = constructTreePreorder();
    root->right = constructTreePreorder();

    return root;
}

void bfsTraversal(node* root){
    int level = 0;
    queue<pair<node*,int>> upcoming;
    upcoming.push({root,level});

    int currLevel = 0;
    while (!upcoming.empty()){
        node* curr = upcoming.front().first;
        int l = upcoming.front().second;
        upcoming.pop();
        if (l > currLevel){
            cout<<endl;
            currLevel++;
        }
        cout<<curr->data<<" ";
        if (curr->left != NULL)
            upcoming.push({curr->left,l+1});
        if (curr->right != NULL)
            upcoming.push({curr->right,l+1});
    }
    cout<<endl;
}

int main() {
    node* tree;
    node* root = constructTreePreorder();
    bfsTraversal(root);
    return 0;
}

