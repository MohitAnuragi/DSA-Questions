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
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* node = root;
        while (node) {
            TreeNode* savedRight = node->right; 
            if (node->left) {
                TreeNode* tempR = node->left;

                TreeNode* rightmost = tempR;
                while (rightmost->right) {
                    rightmost = rightmost->right;
                }
                rightmost->right = savedRight;
                node->right = node->left;
                node->left = nullptr;   
            }
            node = node->right;
        }
    }
};

