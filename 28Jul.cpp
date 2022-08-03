// Question- check if binary tree is balanced

#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}

pair<int,bool> isHeightBalancedOptimised(node *root)
{
    // Write your code here
    if (root == NULL){
        return {0,true};
    }

    if (root->left == NULL and root->right == NULL){
        return {1,true};
    }

    pair<int,bool> l = isHeightBalancedOptimised(root->left);
    pair<int,bool> r = isHeightBalancedOptimised(root->right);

    int height = max(l.first, r.first) + 1;
    if (abs(l.first-r.first) <= 1 and l.second and r.second){
        return {height,true};
    }
    
    return {height,false};
}

int main()
{
    node *root = build("true");

    cout << boolalpha << isHeightBalancedOptimised(root).second;

    return 0;
}
