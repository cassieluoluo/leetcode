/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root) {
    int sum = 0;
    if (!root) return sum;
    dfs(root, 0, &sum);
    return sum;
}

void dfs(struct TreeNode* node, int val, int *sum) {
    val = val * 10 + node->val;
    if (node->left == NULL && node->right == NULL) {
        *sum += val;
        return;
    }
    if (node->left)
        dfs(node->left, val, sum);
    if (node->right)
        dfs(node->right, val, sum);
} // Author: XC