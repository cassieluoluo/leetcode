/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// Author: Xinyu Chen
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return dfs(root->left, root->right);
    }
    
    bool dfs(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left != nullptr && right != nullptr) {
            bool c1 = left->val == right->val;
            bool c2 = dfs(left->left, right->right);
            bool c3 = dfs(left->right, right->left);
            return c1 && c2 && c3;
        }
        return false;
    }
};