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
    int maxPathSum(TreeNode* root) {
        max_val = numeric_limits<int>::min();
        dfs(root);
        return max_val;
    }
    
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int max_left = max(0, dfs(node->left));
        int max_right = max(0, dfs(node->right));
        max_val = max(max_val, max_left + max_right + node->val);
        return max(max_left, max_right) + node->val;
    }
private:
    int max_val;
}; // Author: XC
