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
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
    
    int helper(TreeNode* node, bool isLeft) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) {
            return isLeft ? node->val : 0;
        }
        return helper(node->left, true) + helper(node->right, false);
    }
}; // Author: XC
