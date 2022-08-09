// Question - https://leetcode.com/problems/inorder-successor-in-bst/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr)
            return nullptr;
        
        if (root == p){
            TreeNode *r = root->right;
            while (r != nullptr and r->left != nullptr)
                r = r->left;
            
            return r;
        }
        
        TreeNode* s = nullptr;
        if (root->val > p->val){
            s = inorderSuccessor(root->left,p);
            if (s == nullptr)
                s = root;
        }
        else if (root->val < p->val)
            s = inorderSuccessor(root->right,p);
        
        return s;
    }
