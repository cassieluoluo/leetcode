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
    int rob(TreeNode* root) {
        int rob, norob;
        dfs(root, rob, norob);
        return max(rob, norob);
    }

private:
    void dfs(TreeNode *root, int& rob, int& norob) {
        rob = norob = 0;
        if (root == nullptr) return;
        int left_rob, left_norob, right_rob, right_norob;
        dfs(root->left, left_rob, left_norob);
        dfs(root->right, right_rob, right_norob);
        rob = left_norob + right_norob + root->val;
        norob = max(left_rob, left_norob) + max(right_rob, right_norob);
    }
}; // Author: XC
