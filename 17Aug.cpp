// Question - Given 2 types of queries. Query of type 0 indicates that you read in a value and insert it at the end of your array. Query of type 1 indicates that you read in a value Y, and 2 indices, and you need to find a number X in the array falling in the range of indices given such that X xor Y is maximum.

#include<bits/stdc++.h>
using namespace std;

class node{
public:
    vector<int> indices;
    node *left, *right;
    node(){
        left = right = nullptr;
    }
};

class trie{
public:
    node* root;
    trie(){
        root = new node();
    }

    void insert(int idx, int val){
        root->indices.push_back(idx);
        node* temp = root;
        for (int i=31; i>=0; i--){
            int bit = (val>>i)&1;
            if (bit == 0){
                if (temp->left == nullptr)
                    temp->left = new node();
                temp = temp->left;
            }
            else{
                if (temp->right == nullptr)
                    temp->right = new node();
                temp = temp->right;
            }
            temp->indices.push_back(idx);
        }
    }

    static bool canGo(node* temp, int l, int r){
        int start = temp->indices.lower_bound(temp->indices.begin(), temp->indices.end(), l) - temp->indices.begin();
        int end = temp->indices.upper_bound(temp->indices.begin(), temp->indices.end(), r) - temp->indices.begin();
        return (start < end);
    }

    int maxXor(int l, int r, int val){
        node* temp = root;
        for (int i=31; i>=0; i--){
            int bit = (val>>i)&1;
            if (bit == 0){
                if (temp->right != nullptr and canGo(temp->right,l,r)){
                    temp = temp->right;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if (temp->left != nullptr and canGo(temp->left,l,r)){
                    temp = temp->left;
                }
                else{
                    temp = temp->right;
                }
            }
        }

        return temp->indices[0];
    }
};

int main() {
    int q;
    cin>>q;
    vector<int> v;
    trie t;
    int idx = 0;
    while (q--){
        int type,l,r,val;
        cin>>type>>val;
        if (type == 0){
            v.push_back(val);
            t.insert(val);
            idx++;
        }
        else{
            cin>>l>>r;
            int res = t.maxXor(l,r,val);
            cout<<v[res]<<endl;
        }
    }
    return 0;
}
