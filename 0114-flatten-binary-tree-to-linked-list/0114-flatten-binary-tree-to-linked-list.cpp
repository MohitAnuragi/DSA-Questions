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
class Solution {
public:
    void solve(TreeNode* root, vector<TreeNode*>& pre) {
        if (!root) return;
        pre.push_back(root);
        solve(root->left, pre);
        solve(root->right, pre);
    }
    
    void flatten(TreeNode* root) {
        if (!root) return;
        
        vector<TreeNode*> pre;
        solve(root, pre);  
        
        TreeNode* curr = root;
        for (int i = 1; i < pre.size(); i++) {  
            curr->left = nullptr;     
            curr->right = pre[i];       
            curr = curr->right;       
        }
        
        // last node
        if (curr) {
            curr->left = nullptr;
            curr->right = nullptr;
        }
    }
};