// Question - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";
        string res;
        string val = to_string(root->val);
        string l = serialize(root->left);
        string r = serialize(root->right);
        res.insert(res.end(), val.begin(), val.end());
        res.push_back('l');
        res.insert(res.end(), l.begin(), l.end());
        res.push_back('r');
        res.insert(res.end(), r.begin(), r.end());
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* helper(string &data, int &idx){
        if (idx == data.size())
            return nullptr;
        
        string nodeVal = "";
        while (data[idx] != 'l' and data[idx] != 'r'){
            nodeVal.push_back(data[idx]);
            idx++;
        }
        idx++;
        if (nodeVal.size() == 0)
            return nullptr;
        TreeNode* root = new TreeNode(stoi(nodeVal));
        root->left = helper(data, idx);
        root->right = helper(data, idx);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        int idx=0;
        return helper(data, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
