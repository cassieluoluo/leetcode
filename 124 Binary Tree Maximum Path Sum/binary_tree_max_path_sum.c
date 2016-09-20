/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxPathSum(struct TreeNode* root) {
    int maxval = INT_MIN;
    helper(root, &maxval);
    return maxval;
}

int helper(struct TreeNode *node, int *maxval) {
    if (!node) return 0;
    int lt = helper(node->left, maxval);
    int rt = helper(node->right, maxval);
    if (lt < 0) lt = 0;
    if (rt < 0) rt = 0;
    int opt = lt + rt + node->val;
    if (opt > *maxval) *maxval = opt;
    return max(lt, rt) + node->val;
}

int max(int a, int b) {
    return a > b ? a : b;
}
// Author: XC
