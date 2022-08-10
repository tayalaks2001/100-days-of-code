// Question - https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int kthSmallest(TreeNode* root, int &k) {
        if (root == NULL)
            return -1;
        
        int ans = kthSmallest(root->left,k);
        if (k <= 0)
            return ans;
        k--;
        if (k == 0)
            return root->val;
        
        return kthSmallest(root->right,k);
    }
