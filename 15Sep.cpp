// Question - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

TreeNode* build(vector<int>& inorder, vector<int>& postorder, int &i, int s, int e){
        if (s > e)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[i--]);
        int pos = find(inorder.begin(),inorder.end(),root->val) - inorder.begin();
        root->right = build(inorder, postorder, i, pos+1, e);
        root->left = build(inorder, postorder, i, s, pos-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = postorder.size()-1;
        return build(inorder, postorder, i, 0, inorder.size()-1);
    }
