/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode *left, struct TreeNode *right) {
    if (!left && !right) return true;
    if (left && right) {
        bool here = left->val == right->val;
        bool lt = helper(left->left, right->right);
        bool rt = helper(left->right, right->left);
        return here && lt && rt;
    }
    return false;
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return helper(root->left, root->right);
} /* Author: XC */
