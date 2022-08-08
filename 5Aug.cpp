// Question - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<bool,bool> lca(TreeNode* root, TreeNode* a, TreeNode* b, TreeNode* &ans){
        if (root == NULL)
            return {false,false};

        pair<bool,bool> res = {false,false};
        if (root == a)
            res.first = true;
        if (root == b)
            res.second = true;

        pair<bool,bool> l = lca(root->left,a,b,ans);
        pair<bool,bool> r = lca(root->right,a,b,ans);

        if ((l.first and r.second) or (l.second and r.first))
            ans = root;

        if ((res.first and (l.second or r.second)) or (res.second and (l.first or r.first)))
            ans = root;

        res.first = res.first or l.first or r.first;
        res.second = res.second or l.second or r.second;

        return res;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        lca(root, p, q, ans);
        return ans;
    }
};
