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
class Solution {//brute force : Time Complexity: O(n²) & Space Complexity: O(n)
public:
    // store except the key
    void collectValues(TreeNode* root, int key, vector<int>& vals) {
        if (!root) return;
        if (root->val != key) {
            vals.push_back(root->val);
        }
        collectValues(root->left, key, vals);
        collectValues(root->right, key, vals);
    }
    
    // Insert into BST
    TreeNode* insertBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) {
            root->left = insertBST(root->left, val);
        } else if (val > root->val) {
            root->right = insertBST(root->right, val);
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        vector<int> vals;
        collectValues(root, key, vals);
        
        // Rebuild tree from scratch
        TreeNode* newRoot = nullptr;
        for (int val : vals) {
            newRoot = insertBST(newRoot, val);
        }
        return newRoot;
    }
};