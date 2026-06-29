/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxPath(TreeNode* root, int& sum) {
        if (!root) {
            return 0;
        }
        int lsum = maxPath(root->left, sum);
        int rsum = maxPath(root->right, sum);

        int temp = max(max(lsum, rsum) + root->val, root->val); // checking for rest path
        int ans = max(temp, lsum + rsum + root->val); // best path may be completed
        sum = max(sum, ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxPath(root, sum);
        return sum;
    }
};