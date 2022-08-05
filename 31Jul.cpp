// Question - general tree operations: find height, diameter, replace node values with sum of child nodes and own value, check if tree is balanced

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

void replaceWithSum(node* &root){
    if (root == NULL)
        return;
    
    replaceWithSum(root->l);
    replaceWithSum(root->r);
    if (root->l != NULL)
        root->data += root->l->data;
    if (root->r != NULL)
        root->data += root->r->data;
}

int height(node* root){
    if (root == NULL)
        return 0;
    
    int h1 = height(root->l), h2 = height(root->r);
    return max(h1,h2) + 1;
}

int diameter(node* root){
    if (root == NULL)
        return 0;

    int h1 = height(root->l), h2 = height(root->r);
    return max(h1+h2, max(diameter(root->l), diameter(root->r)));
}

pair<int,int> diameterEfficient(node* root){
    if (root == NULL)
        return {0,0};
    
    pair<int,int> left = diameterEfficient(root->l);
    pair<int,int> right = diameterEfficient(root->r);

    pair<int,int> res;
    res.first = max(left.first,right.first) + 1;
    res.second = max(left.first+right.first, max(left.second,right.second));

    return res;
}

// checks if diff in height of left child and right child is <= 1 for all nodes
pair<bool,int> isBalanced(node* root){
    pair<bool,int> p;
    if (root == NULL){
        p.first = true;
        p.second = 0;
        return p;
    }

    pair<bool,int> left = isBalanced(root->l);
    pair<bool,int> right = isBalanced(root->r);

    p.first = (left.first and right.first and abs(left.second-right.second)<=1);
    p.second = max(left.second,right.second) + 1;
    return p;
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

// sample input for building tree - 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 14 -1 -1 13 -1 -1
// driver
int main() {
    node* root = buildTree();
    printLevelwise(root);
    replaceWithSum(root);
    printLevelwise(root);
    cout<<"Diameter I: "<<diameter(root)<<endl;
    cout<<"Diameter II: "<<diameterEfficient(root).second<<endl;
    cout<<endl<<boolalpha<<isBalanced(root).first<<endl;
    return 0;
}

