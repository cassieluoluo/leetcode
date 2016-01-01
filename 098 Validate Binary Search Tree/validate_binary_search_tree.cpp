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
    bool isValidBST(TreeNode* root) {
        return dfs(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
    
    bool dfs(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return dfs(node->left, minVal, node->val) && dfs(node->right, node->val, maxVal);
    }
};