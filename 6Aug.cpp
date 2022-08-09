// Question - https://leetcode.com/problems/delete-node-in-a-bst/

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

TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        
        if (root->val == key){
            if (root->left == nullptr and root->right == nullptr){
                delete root;
                return NULL;
            }
            else if (root->left == nullptr or root->right == nullptr){
                TreeNode* temp = (root->left == nullptr)?root->right:root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* temp = root->left;
                while (temp ->right != NULL)
                    temp = temp->right;
                root->val = temp->val;
                root->left = deleteNode(root->left,temp->val);
            }
        }
        else if (root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        
        return root;
}

