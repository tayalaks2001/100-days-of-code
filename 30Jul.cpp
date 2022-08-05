// Question - alternative method to print tree level-wise; more mem efficient than before

#include <bits/stdc++.h>
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

node* buildTree(){
    int d;
    cin>>d;
    if (d == -1)
        return NULL;
    
    node* root = new node(d);
    root->l = buildTree();
    root->r = buildTree();

    return root;
}

void printLevelwise(node* root){
    queue<node*> traversal;
    traversal.push(root);
    traversal.push(NULL);
    while(!traversal.empty()){
        node* curr = traversal.front();
        if (curr == NULL){
            cout<<endl;
            traversal.pop();
            if (!traversal.empty()){
                traversal.push(NULL);
            }
            continue;
        }
        cout<<curr->data<<" ";
        traversal.pop();
        if (curr->l != NULL)
            traversal.push(curr->l);
        if (curr->r != NULL)
            traversal.push(curr->r);
    }
    cout<<endl;
}
