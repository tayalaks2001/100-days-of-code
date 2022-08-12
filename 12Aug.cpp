// Question - https://leetcode.com/problems/validate-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;

bool isBST(TreeNode* root, TreeNode* min, TreeNode* max){
        if (root == nullptr)
            return true;
        
        if (min and root->val <= min->val)
            return false;
        
        if (max and root->val >= max->val)
            return false;
        
        return isBST(root->left,min,root) and isBST(root->right,root,max);
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode *min = nullptr, *max = nullptr;
        return isBST(root,min,max);
    }
