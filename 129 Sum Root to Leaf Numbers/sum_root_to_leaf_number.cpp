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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        int num = 0, sum = 0;
        dfs(root, num, sum);
        return sum;
    }
    
    void dfs(TreeNode* node, int num, int& sum) {
        num = num * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            sum += num;
            return;
        }
        if (node->left != nullptr) dfs(node->left, num, sum);
        if (node->right != nullptr) dfs(node->right, num, sum);
    }
};