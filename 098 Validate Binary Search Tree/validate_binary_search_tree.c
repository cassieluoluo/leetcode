/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode *node, long curr_min, long curr_max) {
    if (node == NULL) return true;
    if (node->val <= curr_min || node->val >= curr_max) return false;
    return dfs(node->left, curr_min, node->val) && dfs(node->right, node->val, curr_max);
}

bool isValidBST(struct TreeNode* root) {
    return dfs(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
} /* Author: XC */
